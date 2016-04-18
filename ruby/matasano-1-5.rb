# Implement repeating-key XOR
# Here is the opening stanza of an important work of the English language:
# 
# Burning 'em, if you ain't quick and nimble
# I go crazy when I hear a cymbal
# Encrypt it, under the key "ICE", using repeating-key XOR.
# 
# In repeating-key XOR, you'll sequentially apply each byte of the key; the first byte of plaintext will be XOR'd against I, the # next C, the next E, then I again for the 4th byte, and so on.
# 
# It should come out to:
# 
# 0b3637272a2b2e63622c2e69692a23693a2a3c6324202d623d63343c2a26226324272765272
# a282b2f20430a652e2c652a3124333a653e2b2027630c692b20283165286326302e27282f
# Encrypt a bunch of stuff using your repeating-key XOR function. Encrypt your mail. Encrypt your password file. Your .sig file. Get a feel for it. I promise, we aren't wasting your time with this.

expected_result = "0b3637272a2b2e63622c2e69692a23693a2a3c6324202d623d63343c2a26226324272765272a282b2f20430a652e2c652a3124333a653e2b2027630c692b20283165286326302e27282f"

class String
	def xor(key)
		i = 0
		s = []
		self.each_byte do |c|
			s.push((c ^ key[i].ord).chr)
			
			i += 1
			i = 0 if i >= key.length
		end
		s.join
	end

	def to_hex
		self.each_byte.map { |c| "%02x" % c}.join
	end
end

class Array
	def xor(key)
		self.map { |x| (x ^ key).chr }.join
	end
end

s = "Burning 'em, if you ain't quick and nimble
I go crazy when I hear a cymbal"

result = s.xor("ICE").to_hex

puts result