#!/usr/bin/env ruby

def solution(n, l, necklaces)
  sorted = necklaces.map do |necklace|
    l.times.map do |i|
      next necklace if i == 0
      necklace[i..-1] + necklace[0..(i-1)]
    end.sort.first
  end
  sorted.uniq.count
end

def main
  n, l = gets.split.map(&:to_i)
  necklaces = n.times.map do |i|
    gets.strip
  end
  print solution(n, l, necklaces)
end

main
