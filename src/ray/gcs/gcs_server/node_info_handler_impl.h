#ifndef RAY_GCS_NODE_INFO_HANDLER_IMPL_H
#define RAY_GCS_NODE_INFO_HANDLER_IMPL_H

#include "ray/gcs/redis_gcs_client.h"
#include "ray/rpc/gcs_server/gcs_rpc_server.h"

namespace ray {
namespace rpc {

/// This implementation class of `NodeInfoHandler`.
class DefaultNodeInfoHandler : public rpc::NodeInfoHandler {
 public:
  explicit DefaultNodeInfoHandler(gcs::RedisGcsClient &gcs_client)
      : gcs_client_(gcs_client) {}

  void HandleRegisterNode(const RegisterNodeRequest &request, RegisterNodeReply *reply,
                          SendReplyCallback send_reply_callback) override;

  void HandleUnregisterNode(const UnregisterNodeRequest &request,
                            UnregisterNodeReply *reply,
                            SendReplyCallback send_reply_callback) override;

  void HandleGetAllNodeInfo(const GetAllNodeInfoRequest &request,
                            GetAllNodeInfoReply *reply,
                            SendReplyCallback send_reply_callback) override;

 private:
  gcs::RedisGcsClient &gcs_client_;
};

}  // namespace rpc
}  // namespace ray

#endif  // RAY_GCS_NODE_INFO_HANDLER_IMPL_H
