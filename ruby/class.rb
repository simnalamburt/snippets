class Greeter
  attr_accessor :name

  def initialize(names = {world: 'World!'})
    @names = names
  end

  def hi_all
    if @names.respond_to? 'each'
      @names.each do |k, v|
        hi k, v
      end
    else
      hi k, v
    end
  end

  def hi position, name
    if position == :TA1 or position == :TA2
      puts "Hi #{position} #{name}!"
    elsif position == :Professor
      puts "Hello #{position} #{name}!"
    else
      puts "Hi #{name}!"
    end
  end

  def bye
    puts "Bye #{@name}"
  end
end

hash = {
  TA1: 'Taehun',
  TA2: 'JooSeon',
  Professor: '전병곤',
  Student1: '김지현'
}

a = Greeter.new hash

a.hi_all
