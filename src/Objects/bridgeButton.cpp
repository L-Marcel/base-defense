#include <Objects/bridgeButton.hpp>

namespace Game{
  void BridgeButton::step(){
    Vector<float> mousePos = Mouse::position(&this->gp->window);
    if(this->gp->checkPaused()){
      if(mousePos.x <= (this->position.x + this->buttonWidth) &&
         mousePos.x >= (this->position.x - this->buttonWidth) &&
         mousePos.y <= (this->position.y + this->buttonHeight) &&
         mousePos.y >= (this->position.y - this->buttonHeight))
        {
          if(Mouse::left()){
            for(unsigned int i = 0; i < this->bridgeTypes.size(); i++){
              for(unsigned int j = 0; j < this->gp->buttons.length(); j++){
                Button* bt = this->gp->buttons.get(j);
                string btype = this->bridgeTypes[i];     
                if(bt->subType() == btype){
                  if(!bt->wasBridged()){
                    bt->setVisible(true);
                    bt->setBridged(true);
                    bt->setClicked(false);
                  }
                } else if(bt->subType() != btype){
                  if(!bt->wasBridged()){
                    bt->setVisible(false);
                  }
                }
              }
            }
            this->setClicked(true);

            for(unsigned int i = 0; i < this->gp->buttons.length(); i++){
              Button* desbridge = this->gp->buttons.get(i);
              desbridge->setBridged(false);
            }
          }
      }
    }
    if(this->getClicked()){
      this->visible = false;
    }
  };
  
  BridgeButton::~BridgeButton(){};

  BridgeButton* BridgeButton::create(GameProcess* gp, string sprite, Box box, bool pauseBt, string initialSubType){
    BridgeButton* bridgeButton = new BridgeButton(sprite, box);
    bridgeButton->pausable = !pauseBt;
    bridgeButton->buttonWidth = box.getSize().x;
    bridgeButton->buttonHeight = box.getSize().y;
    bridgeButton->subTypeVar = initialSubType;
    bridgeButton->gp = gp;
    bridgeButton->addType(bridgeButton->subType());
    gp->objects.add(bridgeButton);
    gp->buttons.add(bridgeButton);
    return bridgeButton;
  };

  void BridgeButton::addType(string subType){
    this->bridgeTypes.push_back(subType);
  }
}