#!/usr/bin/env ruby
# frozen_string_literal: true
require 'fileutils'
FileUtils.remove_dir '가', true
FileUtils.remove_dir '가'.unicode_normalize(:nfd), true
FileUtils.mkdir_p '가/나/다/라/마/바'.unicode_normalize :nfd
FileUtils.touch '가/나/다/라/마/바/사'.unicode_normalize :nfd
