#ifndef ISPN_HOTROD_OPERATIONS_REMOVEIFUNMODIFIEDOPERATION_H
#define ISPN_HOTROD_OPERATIONS_REMOVEIFUNMODIFIEDOPERATION_H

#include "infinispan/hotrod/RemoteCacheBase.h"
#include "hotrod/impl/operations/AbstractKeyOperation.h"
#include "hotrod/impl/VersionedOperationResponse.h"

namespace infinispan {
namespace hotrod {
class Topology;
namespace operations {

class RemoveIfUnmodifiedOperation
    : public AbstractKeyOperation<VersionedOperationResponse>
{
    protected:
        VersionedOperationResponse executeOperation(
            infinispan::hotrod::transport::Transport& transport);

    private:
        RemoveIfUnmodifiedOperation(
            const infinispan::hotrod::protocol::Codec& codec,
            std::shared_ptr<transport::TransportFactory> transportFactory,
            const std::vector<char>& key, const std::vector<char>& cacheName,
            Topology& topologyId, uint32_t flags, int64_t version);

        int64_t version;

    friend class OperationsFactory;
};

}}} // namespace infinispan::hotrod::operations

#endif  // ISPN_HOTROD_OPERATIONS_REMOVEIFUNMODIFIEDOPERATION_H
