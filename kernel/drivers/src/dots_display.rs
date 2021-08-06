use kernel::hil::led::Led;
use kernel::process::{Error, ProcessId};
use kernel::syscall::{CommandReturn, SyscallDriver};
use kernel::ErrorCode;

pub const DRIVER_NUM: usize = 0xa0001;

// Array cifre 
const DIGITS:[u32; 10] = [
    0b11111_10011_10101_11001_11111, // 0
    0b01100_00100_00100_00100_00100, // 1
    0b01110_10001_00110_01000_11111, // 2
    0b11111_00001_00111_00001_11111, // 3
    0b10001_10001_11111_00001_00001, // 4
    0b11111_10000_11111_00001_11111, // 5
    0b11111_10000_11111_10001_11111, // 6
    0b11111_00001_00010_00100_01000, // 7
    0b11111_10001_01110_10001_11111, // 8
    0b11111_10001_11111_00001_11111, // 9
];

pub struct DotsDisplay<'a, L: Led> {
    leds: &'a [&'a L; 25],
}

impl<'a, L: Led> DotsDisplay<'a, L> {
    pub fn new(leds: &'a [&'a L; 25]) -> DotsDisplay<'a, L> {
        DotsDisplay { leds }
    }

    fn display (&self, digit: char) {
        let digit_index = digit as usize - '0' as usize;
        let current_digit = DIGITS[digit_index];
        for index in 0..25 {
            let bit = (current_digit >> (24-index)) & 0x1;
            if bit == 1 {
                self.leds[index].on();
            }
            else
            {
                self.leds[index].off();
            }
        }
    }
}

impl<'a, L: Led> SyscallDriver for DotsDisplay<'a, L> {
    fn command(
        &self,
        command_num: usize,
        r2: usize,
        _r3: usize,
        _process_id: ProcessId,
    ) -> CommandReturn {
        match command_num {
            0 => CommandReturn::success(),
            // print digit
            1 => match char::from_u32(r2 as u32) {
                Some(digit) => {
                    if digit >= '0' && digit <= '9' {
                        self.display (digit);
                        CommandReturn::success()
                    } else {
                        CommandReturn::failure(ErrorCode::INVAL)
                    }
                }
                None => CommandReturn::failure(ErrorCode::INVAL),
            },
            _ => CommandReturn::failure(ErrorCode::NOSUPPORT),
        }
    }

    fn allocate_grant(&self, _process_id: ProcessId) -> Result<(), Error> {
        Ok(())
    }
}