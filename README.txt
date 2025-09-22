
# all cards sorted by rarity, class, cost and name
cat CARDS.txt | perl -ne 'print "$1\t$2\t$3\n" if $_ =~ /^(#\S+) (\S+) (.*)?$/' | sort -k1 | column -ts $'\t'

# all cards sorted by cost and name
cat CARDS.txt | perl -ne 'print "$1\t$2\t$3\n" if $_ =~ /^(#\S+) (\S+) (.*)?$/' | sort -k2 | column -ts $'\t'

# all legendary cards sorted by cost and name
cat CARDS.txt | perl -ne 'print "$1\t$2\t$3\n" if $_ =~ /^(#50\S+) (\S+) (.*)?$/' | sort -k2 | column -ts $'\t'

# all weapons sorted by rarity, class, cost and name
cat CARDS.txt | perl -ne 'print "$1\t$2\t$3\n" if $_ =~ /^(#\S+) (\S+_\d_\d) (.*)?$/' | sort -k1 | column -ts $'\t'

# all mage spells sorted by cost and name
cat CARDS.txt | perl -ne 'print "$1\t$2\t$3\n" if $_ =~ /^(#\S3\S+) (\S+\D) (.*)?$/' | sort -k2 | column -ts $'\t'

# all neutral beasts sorted by cost and name
cat beasts.txt | perl -ne 'print "$1\t$2\t$3\n" if $_ =~ /^(#\S0\S+) (\S+\D) (.*)?$/' | sort -k2 | column -ts $'\t'

# all neutral/hunter minions sorted by cost and name
cat CARDS.txt | perl -ne 'print "$1\t$2\t$3\n" if $_ =~ /^(#\S(?:0|2)\S+) (\S+_\d\d_\d\d) (.*)?$/' | sort -k2 | column -ts $'\t'

# top 10 minions with the greatest attack
cat CARDS.txt | perl -ne 'print "$1\t$2\t$3\t$4\t$5\t$6\n" if $_ =~ /^(#\S+) (\d\d)_(\S+)_(\d\d)_(\d\d) (.*)?$/' | sort -k4 -r | column -ts $'\t' -N'id,cost,name,atk,hp,desc' | head -n10

