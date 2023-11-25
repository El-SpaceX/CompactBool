#include <cstdint>
#include <string>


template<uint8_t bits>
class CompactBool {
private:
    static_assert(bits <= 64 && bits > 0, "The minimum size is 1 (if you are going to use 1, use bool instead, it is more efficient) and the maximum is 64.");
    static_assert(bits > 1, "If you only want to use 1 bit, it is recommended that you use the default bool, for performance reasons.");

    using Type = std::conditional_t<(bits <= 8), uint8_t,
                  std::conditional_t<(bits <= 16), uint16_t,
                  std::conditional_t<(bits <= 32), uint32_t,
                  std::conditional_t<(bits <= 64), uint64_t,
                      void>>>>;

    Type iCompactBool = 0;

    inline bool IsValidSlot(const uint8_t slot) {
        return (1 <= slot <= bits);
    }
public:

    CompactBool() {};
    CompactBool(const Type value) : iCompactBool(value) {};

    inline void Set(const uint8_t slot, const bool value) {
        if(!IsValidSlot(slot))
            return;

        if(value) {
            this->iCompactBool |= 1 << (slot-1);
        } else {
            this->iCompactBool &= ~(1 << slot-1);
        }
    }

    inline bool Get(const uint8_t slot) {
        if(!IsValidSlot(slot))
            return false;

        return static_cast<bool>((iCompactBool >> slot-1) & 0x1);
    }

    inline Type GetValueBrute() {
        return iCompactBool;
    }

    inline void SetValueBrute(const Type value) {
        iCompactBool = value;
    }

    inline std::string GetBin() {
        std::string bin;
        for (int i = bits - 1; i >= 0; i--) {
            bin += ((iCompactBool >> i) & 0x1) ? '1' : '0';
        }
        return bin;
    }
};