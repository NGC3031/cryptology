# Convert an integer to a binary string using Python string formatting
import binascii
import sys
from os import urandom

def genkey(length: int) -> bytes:
    """Generate key."""
    return bin(int.from_bytes(urandom(length), byteorder=sys.byteorder))

message="This is a another longer message"
# convert string to array
mArr = list(message)

for i in range(len(mArr)):
    mArr[i]= f'{ord(mArr[i]):b}'

m=list("".join(mArr))
print("Message: ", "".join(m))
#print("\nLM: ", len(m))

key = genkey(len(message))
key = key[2:len(m)+2]
print('Key:', key)
#print("\nLK",len(key))

#Now the message and key are the same length
# Do the XOR
c=m
for i in range(len(m)):
    c[i]=int(m[i])^int(key[i])

print("Cipher: ","".join(str(v) for v in c))

# Now test it by working backwards
for i in range(len(m)):
    m[i]=int(key[i])^int(c[i])
mStr="".join(str(v) for v in m)
print("C(k)=M: ", mStr)

n = 7
chars = [c for c in mStr]
ngrams = []
for i in range(len(chars)-n + 1):
  ngram = "".join(chars[i:i+n])
  ngrams.append(chr(int(ngram,2)))
print("mStr: ", ngrams)
