# frozen_string_literal: true

# Reference:
#   https://twitter.com/kkkuuukkuuuuu/status/1190273087717040129

def enc input
  input.encode 'utf-8', 'cp949', invalid: :replace, undef: :replace, replace: '?'
end

#A = ('가'..'힣').select { |x| /2\?몄꽑/ === enc("2#{x}선") } .join
#A = <<EOF.delete("\n")
#끸낸냸넸노놸뇸눸뉸늸닸댸델뎸돸됸둸뒸듸딸땸떸뗸똸뙸뚸뛸뜸띸랸럸렸쁸삸샸세셸솸쇸숸
#쉸슸싸쌸썸쎸쏸쐸쑸쒸쓸씸앸언엸옸외울웸윸인잸쟸져큸킸탸털텸톸퇸툸퉸트틸팸퍸편폸퐸
#푸풸퓸픸핸햸헸호홸횸훸휸흸
#EOF
A = '호'

#B = ('가'..'힣').select { |x| /\?꾧뎄/ === enc("#{x}구") } .join
#B = <<EOF.delete("\n")
#뀄끄낄냄넄년놄뇄누뉄늄닄댄덄뎄도됄둄뒄듄딄땄떄뗄똄뙄뚄뛄뜄띄랄럄렄쀄쁄삄샄섄셄솄
#쇄숄쉄슄싄쌄썄쎄쏄쐄쑄쒄쓄씄아얄엄옄완욄웄위을임쟄전퀄큄킄탄턄텄톄퇄툄퉄튄틄팄퍄
#펄폄퐄푄풄퓄프필햄헄현홄횄후휄흄힄
#EOF
B = '누도아엄완위을임전탄프현후'

#C = ('가'..'힣').select { |x| /\?꾩감/ === enc("#{x}차") } .join
#C = <<EOF.delete("\n")
#뀄끄낄냄넄년놄뇄누뉄늄닄댄덄뎄도됄둄뒄듄딄땄떄뗄똄뙄뚄뛄뜄띄랄럄렄쀄쁄삄샄섄셄솄
#쇄숄쉄슄싄쌄썄쎄쏄쐄쑄쒄쓄씄아얄엄옄완욄웄위을임쟄전퀄큄킄탄턄텄톄퇄툄퉄튄틄팄퍄
#펄폄퐄푄풄퓄프필햄헄현홄횄후휄흄힄
#EOF
C = '전'

#D = ('가'..'힣').select { |x| /\?⑥쟾/ === enc("#{x}전") } .join
#D = <<EOF.delete("\n")
#뀨끨남냨넨녨놨뇨눨뉨늨단댨덨뎨돨됨둨뒨듨딨땨떨뗨똨뙨뚨뛨뜨띨램럨련쀨쁨삨샨섨셨솨
#쇨숨쉨슨싨쌨써쎨쏨쐨쑨쒨쓨씨앨얨엨온왨욨웨율읨잨쟨젨퀨큨킨탨턨텨톨퇨툨퉨튨틨패퍨
#펨폨퐨푨풨퓨픨함햨헨혨홨효훨휨흨
#EOF
D = '단'

puts '2A선 B구C차D전'
puts 'A: ' + A
puts 'B: ' + B
puts 'C: ' + C
puts 'D: ' + D
puts

for a in A.each_char
  for b in B.each_char
    for c in C.each_char
      for d in D.each_char
        orig = "2#{a}선 #{b}구#{c}차#{d}전"
        puts "#{orig} (#{enc(orig)})"
      end
    end
  end
end

# '2?몄꽑  ?꾧뎄??꾩감???⑥쟾'.encode('cp949').decode('utf-8', 'replace')
# '2?�선  ?�구??�차???�전'
