def divide(range, dividend)
  begin_ = range.begin
  end_ = range.end
  count = end_ - begin_

  if range.exclude_end?
    (0...dividend).map { |i| (count*i/dividend + begin_) ... (count*(i+1)/dividend + begin_) }
  else
    (0...dividend).map do |i|
      i < dividend - 1 ?
        (count*i/dividend + begin_) ... (count*(i+1)/dividend + begin_) :
        (count*i/dividend + begin_) .. end_
    end
  end
end

p divide(1   ... 1000, 3)
p divide(1   ..  1000, 3)
p divide(1.2 ... 1.8, 3)
p divide(1.2 ..  1.8, 3)
