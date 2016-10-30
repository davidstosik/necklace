#!/usr/bin/env ruby

require 'pry'
require 'benchmark'

script = ARGV[0]

Dir['tests/*.txt'].each do |file|
  result = nil
  time = Benchmark.measure do
    4.times do
      `./#{script} < #{file}`
    end
    result = `./#{script} < #{file}`
  end

  expected = file.match(/(?<=-)\d+(?=\.)/)[0]
  if result == expected
    puts "#{'%.4f' % time.real}s <= #{file}"
  else
    puts "failed test #{file} with #{result} instead of #{expected}"
  end
end
