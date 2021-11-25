extern crate serde_json;
extern crate elp;

use serde_json::json;
use std::io::BufRead;

fn main() {
    for line in std::io::stdin().lock().lines() {
        let line = line.unwrap();
        let record = elp::parse_record(&line).unwrap();
        println!(
            "{}",
            json!({
                "timestamp":                 record.timestamp.to_rfc3339(),
                "elb_name":                  record.elb_name,
                "client_address":            record.client_address,
                "backend_address":           record.backend_address,
                "request_processing_time":   record.request_processing_time,
                "backend_processing_time":   record.backend_processing_time,
                "response_processing_time":  record.response_processing_time,
                "elb_status_code":           record.elb_status_code,
                "backend_status_code":       record.backend_status_code,
                "received_bytes":            record.received_bytes,
                "sent_bytes":                record.sent_bytes,
                "request_method":            record.request_method,
                "request_url":               record.request_url,
                "request_http_version":      record.request_http_version,
                "user_agent":                record.user_agent,
                "ssl_cipher":                record.ssl_cipher,
                "ssl_protocol":              record.ssl_protocol,
            })
        );
    }
}
