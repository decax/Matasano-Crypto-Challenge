# Fixed XOR
# Write a function that takes two equal-length buffers and produces their XOR combination.
# 
# If your function works properly, then when you feed it the string:
# 
# 1c0111001f010100061a024b53535009181c
# ... after hex decoding, and when XOR'd against:
# 
# 686974207468652062756c6c277320657965
# ... should produce:
# 
# 746865206b696420646f6e277420706c6179

hex1 = "1c0111001f010100061a024b53535009181c"
hex2 = "686974207468652062756c6c277320657965"

shouldProduce = "746865206b696420646f6e277420706c6179"

class String
	def to_binbuf
		self.scan(/../).map { |x| x.hex }
	end
end

hex1_binary = hex1.to_binbuf
hex2_binary = hex2.to_binbuf

xored = hex1_binary.zip(hex2_binary).map { |x, y| x ^ y }

# puts xored.map { |x| x.chr }.join

result = xored.map { |x| x.to_s(16) }.join

puts result