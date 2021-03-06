/**
 * Autogenerated by Thrift Compiler (0.9.1)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef Serv_H
#define Serv_H

#include <thrift/TDispatchProcessor.h>
#include "student_types.h"



class ServIf {
 public:
  virtual ~ServIf() {}
  virtual int32_t put(const Student& s) = 0;
};

class ServIfFactory {
 public:
  typedef ServIf Handler;

  virtual ~ServIfFactory() {}

  virtual ServIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(ServIf* /* handler */) = 0;
};

class ServIfSingletonFactory : virtual public ServIfFactory {
 public:
  ServIfSingletonFactory(const boost::shared_ptr<ServIf>& iface) : iface_(iface) {}
  virtual ~ServIfSingletonFactory() {}

  virtual ServIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler(ServIf* /* handler */) {}

 protected:
  boost::shared_ptr<ServIf> iface_;
};

class ServNull : virtual public ServIf {
 public:
  virtual ~ServNull() {}
  int32_t put(const Student& /* s */) {
    int32_t _return = 0;
    return _return;
  }
};

typedef struct _Serv_put_args__isset {
  _Serv_put_args__isset() : s(false) {}
  bool s;
} _Serv_put_args__isset;

class Serv_put_args {
 public:

  Serv_put_args() {
  }

  virtual ~Serv_put_args() throw() {}

  Student s;

  _Serv_put_args__isset __isset;

  void __set_s(const Student& val) {
    s = val;
  }

  bool operator == (const Serv_put_args & rhs) const
  {
    if (!(s == rhs.s))
      return false;
    return true;
  }
  bool operator != (const Serv_put_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Serv_put_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class Serv_put_pargs {
 public:


  virtual ~Serv_put_pargs() throw() {}

  const Student* s;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Serv_put_result__isset {
  _Serv_put_result__isset() : success(false) {}
  bool success;
} _Serv_put_result__isset;

class Serv_put_result {
 public:

  Serv_put_result() : success(0) {
  }

  virtual ~Serv_put_result() throw() {}

  int32_t success;

  _Serv_put_result__isset __isset;

  void __set_success(const int32_t val) {
    success = val;
  }

  bool operator == (const Serv_put_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const Serv_put_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Serv_put_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Serv_put_presult__isset {
  _Serv_put_presult__isset() : success(false) {}
  bool success;
} _Serv_put_presult__isset;

class Serv_put_presult {
 public:


  virtual ~Serv_put_presult() throw() {}

  int32_t* success;

  _Serv_put_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

class ServClient : virtual public ServIf {
 public:
  ServClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) :
    piprot_(prot),
    poprot_(prot) {
    iprot_ = prot.get();
    oprot_ = prot.get();
  }
  ServClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) :
    piprot_(iprot),
    poprot_(oprot) {
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  int32_t put(const Student& s);
  void send_put(const Student& s);
  int32_t recv_put();
 protected:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
};

class ServProcessor : public ::apache::thrift::TDispatchProcessor {
 protected:
  boost::shared_ptr<ServIf> iface_;
  virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext);
 private:
  typedef  void (ServProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
  void process_put(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  ServProcessor(boost::shared_ptr<ServIf> iface) :
    iface_(iface) {
    processMap_["put"] = &ServProcessor::process_put;
  }

  virtual ~ServProcessor() {}
};

class ServProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  ServProcessorFactory(const ::boost::shared_ptr< ServIfFactory >& handlerFactory) :
      handlerFactory_(handlerFactory) {}

  ::boost::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::boost::shared_ptr< ServIfFactory > handlerFactory_;
};

class ServMultiface : virtual public ServIf {
 public:
  ServMultiface(std::vector<boost::shared_ptr<ServIf> >& ifaces) : ifaces_(ifaces) {
  }
  virtual ~ServMultiface() {}
 protected:
  std::vector<boost::shared_ptr<ServIf> > ifaces_;
  ServMultiface() {}
  void add(boost::shared_ptr<ServIf> iface) {
    ifaces_.push_back(iface);
  }
 public:
  int32_t put(const Student& s) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->put(s);
    }
    return ifaces_[i]->put(s);
  }

};



#endif
