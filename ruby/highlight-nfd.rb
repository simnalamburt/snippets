# frozen_string_literal: true
ARGF.each { |line| puts line.each_grapheme_cluster.map { |c| c.unicode_normalized?(:nfc) ? c : "\x1b[31m#{c}\x1b[0m" } .join }
