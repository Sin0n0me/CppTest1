// int型かshort型か決定する構造体 enable_ifを参考作成
template <bool IsIntegerType>
struct InputValue {};

template <>
struct InputValue<true> {
	using Type = unsigned int;
};

template <>
struct InputValue<false> {
	using Type = unsigned short;
};

// 値が4バイトか2バイトか判定用の関数
constexpr bool is4ByteType(const unsigned int i) { return i > 0xffff; }

// 型の判定
template <int value>
using InputValue_t = typename InputValue<is4ByteType(value)>::Type;