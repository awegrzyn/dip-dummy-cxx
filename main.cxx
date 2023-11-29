#include <unistd.h> 
#include <dip/Dip.h>
#include <dip/DipSubscription.h>
#include <dip/DipSubscriptionListener.h>
#include <dip/DipData.h>

class DummyListener : public DipSubscriptionListener {
 public:
  void handleMessage(DipSubscription *subscription, DipData &message) {
    std::cout << "Message received" << std::endl;
  }   
  
  void connected(DipSubscription *subscription) {
    std::cout << "Publication source  " << subscription->getTopicName()<< " available" << std::endl;
  }   
    
  void disconnected(DipSubscription *subscription, char *reason) {
    std::cout << "Publication source " << subscription->getTopicName() << " unavailable :" <<  reason << std::endl;
  }   

  void handleException(DipSubscription* subscription, DipException& ex){
    std::cout << "Subscription " << subscription->getTopicName() << " exception: " << ex.what() << std::endl;
 }   
};

int main(int argc, char* argv[]) {
  if (argc != 3) {
    std::cout << "Usage " << argv[0] << " <dip-dns-nodes> <dip-subscription>" << std::endl;
    return 1;
  }
  DipSubscription* sub;
  DipFactory *dip;
  DummyListener listener;
  dip = Dip::create("simpleSubTest");
  dip->setDNSNode(argv[1]);

  sub = dip->createDipSubscription(argv[2], &listener);
  sleep(1000000);
  dip->destroyDipSubscription(sub);
  return 0;
}
