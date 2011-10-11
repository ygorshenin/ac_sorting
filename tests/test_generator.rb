#!/usr/bin/ruby


DEFAULT_RANDOM_MODULO = 1000000000
RANDOM_TEST_SIZES = [1, 10, 100, 1000, 10000, 100000, 1000000, 10000000]
ZERO_TEST_SIZE = 10000000
INCREASING_TEST_SIZE = 10000000
DECREASING_TEST_SIZE = 10000000


def generate_random_records(num_records, file)
  num_records.times { file.puts rand(DEFAULT_RANDOM_MODULO) }
end

def generate_zero_records(num_records, file)
  num_records.times { file.puts 0 }
end

def generate_increasing_records(num_records, file)
  0.upto(num_records - 1) { |i| file.puts i }
end

def generate_decreasing_records(num_records, file)
  (num_records - 1).downto(1) { |i| file.puts i }
end

def generate_test(num_records, path, &method)
  File.open(path, 'w') do |file|
    file.puts num_records
    yield num_records, file
  end
end


Dir.chdir(File.dirname(__FILE__))

RANDOM_TEST_SIZES.each do |num_records|
  STDERR.puts "Generating random file with #{num_records} records..."

  path = "random_#{num_records}.txt"
  generate_test(num_records, path) { |num_records, file|
    generate_random_records(num_records, file)
  }
end

STDERR.puts "Generating file with #{ZERO_TEST_SIZE} zeroes..."
path = "zeroes_#{ZERO_TEST_SIZE}.txt"
generate_test(ZERO_TEST_SIZE, path) { |num_records, file|
  generate_zero_records(num_records, file)
}

STDERR.puts "Generating increasing sequence of size #{INCREASING_TEST_SIZE}..."
path = "increasing_#{INCREASING_TEST_SIZE}.txt"
generate_test(INCREASING_TEST_SIZE, path) { |num_records, file|
  generate_increasing_records(num_records, file)
}

STDERR.puts "Generating decreasing sequence of size #{DECREASING_TEST_SIZE}..."
path = "decreasing_#{DECREASING_TEST_SIZE}.txt"
generate_test(DECREASING_TEST_SIZE, path) { |num_records, file|
  generate_decreasing_records(num_records, file)
}
