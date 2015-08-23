use std::net::{TcpListener, TcpStream};
use std::thread;
use std::io::BufReader;

fn main() {
    let listener = TcpListener::bind("127.0.0.1:3000").unwrap();

    for stream in listener.incoming() {
        match stream {
            Err(_) => { /* 적당히 에러처리 */ }
            Ok(stream) => {
                // 커넥션 성공, 새 스레드에서 처리
                thread::spawn(move|| handle_client(stream));
            }
        }
    }
}

fn handle_client(stream: TcpStream) {
    use std::io::{BufRead, Write}; // BufRead trait 사용

    let mut writer = stream.try_clone().unwrap(); // TODO: 에러처리
    let reader = BufReader::new(stream);

    for line in reader.lines() {
        let line = line.unwrap(); // IO 에러일경우 패닉
        writer.write_all(b"Hello, world!\r\n").unwrap();
        println!("{}", line);
    }
}
