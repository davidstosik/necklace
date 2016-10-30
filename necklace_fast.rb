#!/usr/bin/env ruby

class Array
  def insert_sorted(necklace)
    _insert_sorted(necklace, 0, size)
  end

  def _insert_sorted(necklace, start, length)
    case length
    when 0
      insert(start, necklace)
    when 1
      case necklace <=> at(start)
      when 1
        insert(start + 1, necklace)
      when -1
        insert(start, necklace)
      end
    else
      left_half = length / 2
      pivot = start + left_half
      case necklace <=> at(pivot)
      when 0, 1
        _insert_sorted(necklace, pivot, length - left_half)
      else
        _insert_sorted(necklace, start, left_half)
      end
    end
  end
end

class Necklace < String
  def canonical
    string = self
    result = (size - 1).times.inject(string) do |mem, _|
      string = string[1..-1] + string[0]
      case string <=> mem
      when 0, -1
        mem
      else
        string
      end
    end
  end
end

def solution(n, l, necklaces)
  necklaces.inject([]) do |mem, necklace|
    mem.insert_sorted(Necklace.new(necklace).canonical)
    mem
  end.count
end

def main
  n, l = gets.split.map(&:to_i)
  necklaces = n.times.map do |i|
    gets.strip
  end
  print solution(n, l, necklaces)
end

main
