// LinkedList Based Trie

template <typename IntegerType = int>
struct BinaryTrieNode {
    IntegerType value;
    unsigned int freq;
    BinaryTrieNode<IntegerType>* Child[2];

    BinaryTrieNode() {
        value = 0;
        freq = 0;
        Child[0] = nullptr;
        Child[1] = nullptr;
    }
};

template <typename IntegerType = int, int IntegerSize = 31>
struct BinaryTrie {
    BinaryTrieNode<IntegerType>* root;
    unsigned int size;

    BinaryTrie() {
        root = new BinaryTrieNode<IntegerType>();
        size = 0;
    }

    void insert(IntegerType val) {
        BinaryTrieNode<IntegerType>* iter = root;

        for (int i = IntegerSize; i >= 0; --i) {
            bool bit = (val & (1LL << i));

            if (iter->Child[bit] == nullptr)
                iter->Child[bit] = new BinaryTrieNode<IntegerType>();

            iter = iter->Child[bit];
            ++iter->freq;
        }

        iter->value = val;
        ++size;
    }

    IntegerType minXor(long long val) {
        BinaryTrieNode<IntegerType>* iter = root;
        for (int i = IntegerSize; i >= 0; --i) {
            bool bit = (val & (1LL << i));

            if (iter->Child[bit] != nullptr && iter->Child[bit]->freq > 0)
                iter = iter->Child[bit];
            else if (iter->Child[1 ^ bit] != nullptr && iter->Child[1 ^ bit]->freq > 0)
                iter = iter->Child[1 ^ bit];
        }

        return iter->value;
    }

    void remove(long long val) {
        BinaryTrieNode<IntegerType>* iter = root;

        for (int i = IntegerSize; i >= 0; --i) {
            bool bit = (val & (1LL << i));

            if (iter->Child[bit] != nullptr)
                iter = iter->Child[bit];

            else if (iter->Child[1 ^ bit] != nullptr)
                iter = iter->Child[1 ^ bit];

            --iter->freq;
        }

        --size;
    }
};