/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#pragma once

#include <thrift/lib/cpp2/ServiceIncludes.h>
#include <thrift/lib/cpp2/async/HeaderChannel.h>
#include <thrift/lib/cpp/TApplicationException.h>
#include <thrift/lib/cpp2/async/FutureRequest.h>
#include <folly/futures/Future.h>



#include "seqsvr_types.h"

namespace folly {
  class IOBuf;
  class IOBufQueue;
}
namespace apache { namespace thrift {
  class Cpp2RequestContext;
  class BinaryProtocolReader;
  class CompactProtocolReader;
  namespace transport { class THeader; }
}}

namespace seqsvr {

class AllocServiceSvAsyncIf {
 public:
  virtual ~AllocServiceSvAsyncIf() {}
  virtual void async_tm_FetchNextSequence(std::unique_ptr<apache::thrift::HandlerCallback<std::unique_ptr< ::seqsvr::Sequence>>> callback, int32_t id, int32_t version) = 0;
  // virtual void async_FetchNextSequence(std::unique_ptr<apache::thrift::HandlerCallback<std::unique_ptr< ::seqsvr::Sequence>>> callback, int32_t id, int32_t version) = delete;
  virtual folly::Future<std::unique_ptr< ::seqsvr::Sequence>> future_FetchNextSequence(int32_t id, int32_t version) = 0;
  virtual void async_tm_GetCurrentSequence(std::unique_ptr<apache::thrift::HandlerCallback<std::unique_ptr< ::seqsvr::Sequence>>> callback, int32_t id, int32_t version) = 0;
  // virtual void async_GetCurrentSequence(std::unique_ptr<apache::thrift::HandlerCallback<std::unique_ptr< ::seqsvr::Sequence>>> callback, int32_t id, int32_t version) = delete;
  virtual folly::Future<std::unique_ptr< ::seqsvr::Sequence>> future_GetCurrentSequence(int32_t id, int32_t version) = 0;
};

class AllocServiceAsyncProcessor;

class AllocServiceSvIf : public AllocServiceSvAsyncIf, public apache::thrift::ServerInterface {
 public:
  typedef AllocServiceAsyncProcessor ProcessorType;
  std::unique_ptr<apache::thrift::AsyncProcessor> getProcessor() override;
  virtual void FetchNextSequence( ::seqsvr::Sequence& /*_return*/, int32_t /*id*/, int32_t /*version*/);
  folly::Future<std::unique_ptr< ::seqsvr::Sequence>> future_FetchNextSequence(int32_t id, int32_t version) override;
  void async_tm_FetchNextSequence(std::unique_ptr<apache::thrift::HandlerCallback<std::unique_ptr< ::seqsvr::Sequence>>> callback, int32_t id, int32_t version) override;
  virtual void GetCurrentSequence( ::seqsvr::Sequence& /*_return*/, int32_t /*id*/, int32_t /*version*/);
  folly::Future<std::unique_ptr< ::seqsvr::Sequence>> future_GetCurrentSequence(int32_t id, int32_t version) override;
  void async_tm_GetCurrentSequence(std::unique_ptr<apache::thrift::HandlerCallback<std::unique_ptr< ::seqsvr::Sequence>>> callback, int32_t id, int32_t version) override;
};

class AllocServiceSvNull : public AllocServiceSvIf {
 public:
  void FetchNextSequence( ::seqsvr::Sequence& /*_return*/, int32_t /*id*/, int32_t /*version*/) override;
  void GetCurrentSequence( ::seqsvr::Sequence& /*_return*/, int32_t /*id*/, int32_t /*version*/) override;
};

class AllocServiceAsyncProcessor : public ::apache::thrift::GeneratedAsyncProcessor {
 public:
  const char* getServiceName() override;
  using BaseAsyncProcessor = void;
  using HasFrozen2 = std::false_type;
 protected:
  AllocServiceSvIf* iface_;
  folly::Optional<std::string> getCacheKey(folly::IOBuf* buf, apache::thrift::protocol::PROTOCOL_TYPES protType) override;
 public:
  void process(std::unique_ptr<apache::thrift::ResponseChannel::Request> req, std::unique_ptr<folly::IOBuf> buf, apache::thrift::protocol::PROTOCOL_TYPES protType, apache::thrift::Cpp2RequestContext* context, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm) override;
 protected:
  bool isOnewayMethod(const folly::IOBuf* buf, const apache::thrift::transport::THeader* header) override;
 private:
  static std::unordered_set<std::string> onewayMethods_;
  static std::unordered_map<std::string, int16_t> cacheKeyMap_;
 public:
  using BinaryProtocolProcessFunc = ProcessFunc<AllocServiceAsyncProcessor, apache::thrift::BinaryProtocolReader>;
  using BinaryProtocolProcessMap = ProcessMap<BinaryProtocolProcessFunc>;
  static const AllocServiceAsyncProcessor::BinaryProtocolProcessMap& getBinaryProtocolProcessMap();
 private:
  static const AllocServiceAsyncProcessor::BinaryProtocolProcessMap binaryProcessMap_;
 public:
  using CompactProtocolProcessFunc = ProcessFunc<AllocServiceAsyncProcessor, apache::thrift::CompactProtocolReader>;
  using CompactProtocolProcessMap = ProcessMap<CompactProtocolProcessFunc>;
  static const AllocServiceAsyncProcessor::CompactProtocolProcessMap& getCompactProtocolProcessMap();
 private:
  static const AllocServiceAsyncProcessor::CompactProtocolProcessMap compactProcessMap_;
 private:
  template <typename ProtocolIn_, typename ProtocolOut_>
  void _processInThread_FetchNextSequence(std::unique_ptr<apache::thrift::ResponseChannel::Request> req, std::unique_ptr<folly::IOBuf> buf, std::unique_ptr<ProtocolIn_> iprot, apache::thrift::Cpp2RequestContext* ctx, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm);
  template <typename ProtocolIn_, typename ProtocolOut_>
  void process_FetchNextSequence(std::unique_ptr<apache::thrift::ResponseChannel::Request> req, std::unique_ptr<folly::IOBuf> buf, std::unique_ptr<ProtocolIn_> iprot,apache::thrift::Cpp2RequestContext* ctx,folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm);
  template <class ProtocolIn_, class ProtocolOut_>
  static folly::IOBufQueue return_FetchNextSequence(int32_t protoSeqId, apache::thrift::ContextStack* ctx,  ::seqsvr::Sequence const& _return);
  template <class ProtocolIn_, class ProtocolOut_>
  static void throw_wrapped_FetchNextSequence(std::unique_ptr<apache::thrift::ResponseChannel::Request> req,int32_t protoSeqId,apache::thrift::ContextStack* ctx,folly::exception_wrapper ew,apache::thrift::Cpp2RequestContext* reqCtx);
  template <typename ProtocolIn_, typename ProtocolOut_>
  void _processInThread_GetCurrentSequence(std::unique_ptr<apache::thrift::ResponseChannel::Request> req, std::unique_ptr<folly::IOBuf> buf, std::unique_ptr<ProtocolIn_> iprot, apache::thrift::Cpp2RequestContext* ctx, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm);
  template <typename ProtocolIn_, typename ProtocolOut_>
  void process_GetCurrentSequence(std::unique_ptr<apache::thrift::ResponseChannel::Request> req, std::unique_ptr<folly::IOBuf> buf, std::unique_ptr<ProtocolIn_> iprot,apache::thrift::Cpp2RequestContext* ctx,folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm);
  template <class ProtocolIn_, class ProtocolOut_>
  static folly::IOBufQueue return_GetCurrentSequence(int32_t protoSeqId, apache::thrift::ContextStack* ctx,  ::seqsvr::Sequence const& _return);
  template <class ProtocolIn_, class ProtocolOut_>
  static void throw_wrapped_GetCurrentSequence(std::unique_ptr<apache::thrift::ResponseChannel::Request> req,int32_t protoSeqId,apache::thrift::ContextStack* ctx,folly::exception_wrapper ew,apache::thrift::Cpp2RequestContext* reqCtx);
 public:
  AllocServiceAsyncProcessor(AllocServiceSvIf* iface) :
      iface_(iface) {}

  virtual ~AllocServiceAsyncProcessor() {}
};

class AllocServiceAsyncClient : public apache::thrift::TClientBase {
 public:
  virtual const char* getServiceName();
  typedef std::unique_ptr<apache::thrift::RequestChannel, folly::DelayedDestruction::Destructor> channel_ptr;

  virtual ~AllocServiceAsyncClient() {}

  AllocServiceAsyncClient(std::shared_ptr<apache::thrift::RequestChannel> channel) :
      channel_(channel) {
    connectionContext_.reset(new apache::thrift::Cpp2ConnContext);
  }

  apache::thrift::RequestChannel*  getChannel() {
    return this->channel_.get();
  }

  apache::thrift::HeaderChannel*  getHeaderChannel() {
    return dynamic_cast<apache::thrift::HeaderChannel*>(this->channel_.get());
  }
  virtual void FetchNextSequence(std::unique_ptr<apache::thrift::RequestCallback> callback, int32_t id, int32_t version);
  virtual void FetchNextSequence(apache::thrift::RpcOptions& rpcOptions, std::unique_ptr<apache::thrift::RequestCallback> callback, int32_t id, int32_t version);
 private:
  virtual void FetchNextSequenceImpl(bool useSync, apache::thrift::RpcOptions& rpcOptions, std::unique_ptr<apache::thrift::RequestCallback> callback, int32_t id, int32_t version);
 public:
  virtual void sync_FetchNextSequence( ::seqsvr::Sequence& _return, int32_t id, int32_t version);
  virtual void sync_FetchNextSequence(apache::thrift::RpcOptions& rpcOptions,  ::seqsvr::Sequence& _return, int32_t id, int32_t version);
  virtual folly::Future< ::seqsvr::Sequence> future_FetchNextSequence(int32_t id, int32_t version);
  virtual folly::Future< ::seqsvr::Sequence> future_FetchNextSequence(apache::thrift::RpcOptions& rpcOptions, int32_t id, int32_t version);
  virtual folly::Future<std::pair< ::seqsvr::Sequence, std::unique_ptr<apache::thrift::transport::THeader>>> header_future_FetchNextSequence(apache::thrift::RpcOptions& rpcOptions, int32_t id, int32_t version);
  virtual void FetchNextSequence(folly::Function<void (::apache::thrift::ClientReceiveState&&)> callback, int32_t id, int32_t version);
  static folly::exception_wrapper recv_wrapped_FetchNextSequence( ::seqsvr::Sequence& _return, ::apache::thrift::ClientReceiveState& state);
  static void recv_FetchNextSequence( ::seqsvr::Sequence& _return, ::apache::thrift::ClientReceiveState& state);
  // Mock friendly virtual instance method
  virtual void recv_instance_FetchNextSequence( ::seqsvr::Sequence& _return, ::apache::thrift::ClientReceiveState& state);
  virtual folly::exception_wrapper recv_instance_wrapped_FetchNextSequence( ::seqsvr::Sequence& _return, ::apache::thrift::ClientReceiveState& state);
  template <typename Protocol_>
  void FetchNextSequenceT(Protocol_* prot, bool useSync, apache::thrift::RpcOptions& rpcOptions, std::unique_ptr<apache::thrift::RequestCallback> callback, int32_t id, int32_t version);
  template <typename Protocol_>
  static folly::exception_wrapper recv_wrapped_FetchNextSequenceT(Protocol_* prot,  ::seqsvr::Sequence& _return, ::apache::thrift::ClientReceiveState& state);
  template <typename Protocol_>
  static void recv_FetchNextSequenceT(Protocol_* prot,  ::seqsvr::Sequence& _return, ::apache::thrift::ClientReceiveState& state);
  virtual void GetCurrentSequence(std::unique_ptr<apache::thrift::RequestCallback> callback, int32_t id, int32_t version);
  virtual void GetCurrentSequence(apache::thrift::RpcOptions& rpcOptions, std::unique_ptr<apache::thrift::RequestCallback> callback, int32_t id, int32_t version);
 private:
  virtual void GetCurrentSequenceImpl(bool useSync, apache::thrift::RpcOptions& rpcOptions, std::unique_ptr<apache::thrift::RequestCallback> callback, int32_t id, int32_t version);
 public:
  virtual void sync_GetCurrentSequence( ::seqsvr::Sequence& _return, int32_t id, int32_t version);
  virtual void sync_GetCurrentSequence(apache::thrift::RpcOptions& rpcOptions,  ::seqsvr::Sequence& _return, int32_t id, int32_t version);
  virtual folly::Future< ::seqsvr::Sequence> future_GetCurrentSequence(int32_t id, int32_t version);
  virtual folly::Future< ::seqsvr::Sequence> future_GetCurrentSequence(apache::thrift::RpcOptions& rpcOptions, int32_t id, int32_t version);
  virtual folly::Future<std::pair< ::seqsvr::Sequence, std::unique_ptr<apache::thrift::transport::THeader>>> header_future_GetCurrentSequence(apache::thrift::RpcOptions& rpcOptions, int32_t id, int32_t version);
  virtual void GetCurrentSequence(folly::Function<void (::apache::thrift::ClientReceiveState&&)> callback, int32_t id, int32_t version);
  static folly::exception_wrapper recv_wrapped_GetCurrentSequence( ::seqsvr::Sequence& _return, ::apache::thrift::ClientReceiveState& state);
  static void recv_GetCurrentSequence( ::seqsvr::Sequence& _return, ::apache::thrift::ClientReceiveState& state);
  // Mock friendly virtual instance method
  virtual void recv_instance_GetCurrentSequence( ::seqsvr::Sequence& _return, ::apache::thrift::ClientReceiveState& state);
  virtual folly::exception_wrapper recv_instance_wrapped_GetCurrentSequence( ::seqsvr::Sequence& _return, ::apache::thrift::ClientReceiveState& state);
  template <typename Protocol_>
  void GetCurrentSequenceT(Protocol_* prot, bool useSync, apache::thrift::RpcOptions& rpcOptions, std::unique_ptr<apache::thrift::RequestCallback> callback, int32_t id, int32_t version);
  template <typename Protocol_>
  static folly::exception_wrapper recv_wrapped_GetCurrentSequenceT(Protocol_* prot,  ::seqsvr::Sequence& _return, ::apache::thrift::ClientReceiveState& state);
  template <typename Protocol_>
  static void recv_GetCurrentSequenceT(Protocol_* prot,  ::seqsvr::Sequence& _return, ::apache::thrift::ClientReceiveState& state);
 protected:
  std::unique_ptr<apache::thrift::Cpp2ConnContext> connectionContext_;
  std::shared_ptr<apache::thrift::RequestChannel> channel_;
};

} // seqsvr
namespace apache { namespace thrift {

}} // apache::thrift
