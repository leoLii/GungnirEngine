#include "driver/bgiBase/computeCmdsDesc.h"

GUNGNIR_NAMESPACE_OPEN_SCOPE

namespace driver {

BgiComputeCmdsDesc::BgiComputeCmdsDesc()
    : dispatchMethod(BgiComputeDispatchSerial)
{
}

bool operator==(
    const BgiComputeCmdsDesc& lhs,
    const BgiComputeCmdsDesc& rhs)
{
    return  lhs.dispatchMethod == rhs.dispatchMethod;
}

bool operator!=(
    const BgiComputeCmdsDesc& lhs,
    const BgiComputeCmdsDesc& rhs)
{
    return !(lhs == rhs);
}

}

GUNGNIR_NAMESPACE_CLOSE_SCOPE
