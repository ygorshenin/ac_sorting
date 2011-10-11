#!/usr/bin/ruby

require 'optparse'

DEFAULT_MODULO = 1000000000
DEFAULT_NUM_RECORDS = 1000


def parse_flags(argv)
  options = {
    :modulo => DEFAULT_MODULO,
    :num_records => DEFAULT_NUM_RECORDS,
  }

  parser = OptionParser.new

  parser.on('-m', '--modulo=MODULO', Integer) { |v|
    options[:modulo] = v }
  parser.on('-n', '--num_records=NUM_RECORDS', Integer) { |v|
    options[:num_records] = v }
  parser.on('-s', '--seed=SEED', Integer) { |v|
    options[:seed] = v }

  parser.parse(*argv)

  if options[:modulo] <= 0
    raise ArgumentError.new("modulo must be > 0")
  end
  if options[:num_records] < 0
    raise ArgumentError.new("num_records must be >= 0")
  end

  return options
end

options = parse_flags(ARGV)

srand options[:seed] if options.has_key? :seed

puts options[:num_records]
options[:num_records].times do |i|
  puts rand(options[:modulo])
end
