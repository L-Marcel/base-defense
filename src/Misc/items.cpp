#include <Misc/shop.hpp>
#include <Objects/base.hpp>
#include <Objects/player.hpp>

namespace Game {
  map<string, Item> Shop::items = {
    {
      "heal",
      Item(
        "heal", 
        []() {
          return 0.25;
        },
        [](Item* item) {
          return "Cura imediatamente " + to_string(static_cast<int>(item->upgrade() * 100)) + "% de vida";
        },
        [](Item* item) {
          Player::get()->health.heal(item->upgrade() * Player::get()->health.getLimit());
        },
        []() {
          return 10 + round(0.25 * Player::get()->health.getLimit());
        },
        GUARANTEED
      )
    },
    {
      "repair",
      Item(
        "repair", 
        []() {
          return 0.25;
        },
        [](Item* item) {
          return "Repara imediatamente " + to_string(static_cast<int>(item->upgrade() * 100)) + "% da base";
        },
        [](Item* item) {
          Base::get()->health.heal(item->upgrade() * Base::get()->health.getLimit());
        },
        []() {
          return 10 + round(0.25 * Base::get()->health.getLimit());
        },
        GUARANTEED
      )
    },
    {
      "ammo",
      Item(
        "ammo", 
        []() {
          return 0.25;
        },
        [](Item* item) {
          return "Restaura imediatamente " + to_string(static_cast<int>(item->upgrade() * 100)) + "% da munição";
        },
        [](Item* item) {
          Base::get()->clip.recharge(item->upgrade() * Base::get()->clip.getLimit());
        },
        []() {
          return 10 + round(0.25 * Base::get()->clip.getLimit());
        },
        GUARANTEED
      )
    },
    {
      "base",
      Item(
        "base", 
        []() {
          unsigned short int boost = 10;
          unsigned short int count = 7 - Shop::common_stock.at("base");

          if(count > 5) boost = 50;
          else if(count > 3) boost = 40;
          else if(count > 2) boost = 30;
          else if(count > 1) boost = 20;

          return static_cast<float>(boost);
        },
        [](Item* item) {
          return "Aumenta a vida da base em +" + to_string(static_cast<int>(item->upgrade())) + " pontos";
        },
        [](Item* item) {
          Base::get()->health.upgrade(item->upgrade());
        },
        []() {
          unsigned short int count = 7 - Shop::common_stock.at("base");
          return 30 + (count * 10);
        },
        COMMON
      )
    },
    {
      "health",
      Item(
        "health", 
        []() {
          unsigned short int boost = 10;
          unsigned short int count = 6 - Shop::common_stock.at("health");

          if(count > 3) boost = 40;
          else if(count > 2) boost = 30;
          else if(count > 1) boost = 20;

          return static_cast<float>(boost);
        },
        [](Item* item) {
          return "Aumenta a vida em +" + to_string(static_cast<int>(item->upgrade())) + " pontos";
        },
        [](Item* item) {
          Player::get()->health.upgrade(item->upgrade());
        },
        []() {
          unsigned short int count = 6 - Shop::common_stock.at("health");
          return 30 + (count * 10);
        },
        COMMON
      )
    },
    {
      "max_clip",
      Item(
        "max_clip", 
        []() {
          return 2.0;
        },
        [](Item* item) {
          return "Aumenta a munição do pente em +" + to_string(static_cast<int>(item->upgrade())) + " balas";
        },
        [](Item* item) {
          Player::get()->clip.upgrade(item->upgrade());
        },
        []() {
          unsigned short int count = 4 - Shop::common_stock.at("max_clip");
          return 30 + (count * 10);
        },
        COMMON
      )
    },
    {
      "max_ammo",
      Item(
        "max_ammo", 
        []() {
          unsigned short int boost = 2;
          unsigned short int count = 6 - Shop::common_stock.at("max_ammo");

          if(count > 3) boost = 6;
          else if(count > 1) boost = 4;

          return static_cast<float>(boost);
        },
        [](Item* item) {
          return "Aumenta a munição em +" + to_string(static_cast<int>(item->upgrade())) + " balas";
        },
        [](Item* item) {
          Base::get()->clip.upgrade(item->upgrade());
        },
        []() {
          unsigned short int count = 6 - Shop::common_stock.at("max_ammo");
          return 30 + (count * 10);
        },
        COMMON
      )
    },
    {
      "attack_speed",
      Item(
        "attack_speed", 
        []() {
          unsigned short int count = 4 - Shop::common_stock.at("attack_speed");
          return 1.1 + (0.1 * count);
        },
        [](Item* item) {
          return "Aumenta a velocidade de disparo em +" + to_string(static_cast<int>(round((item->upgrade() - 1.0) * 100.0))) + "%";
        },
        [](Item* item) {
          Player::get()->attack_speed *= item->upgrade();
        },
        []() {
          unsigned short int count = 4 - Shop::common_stock.at("attack_speed");
          return 30 + (count * 15);
        },
        COMMON
      )
    },
    {
      "repair_speed",
      Item(
        "repair_speed", 
        []() {
          unsigned short int count = 9 - Shop::rare_stock.at("repair_speed");
          return 1.1 + (0.05 * count);
        },
        [](Item* item) {
          return "O reparo da base fica +" + to_string(static_cast<int>(round((item->upgrade() - 1.0) * 100.0))) + "% rápido";
        },
        [](Item* item) {
          Base::get()->regeneration *= item->upgrade();
        },
        []() {
          unsigned short int count = 9 - Shop::rare_stock.at("repair_speed");
          return 30 + (count * 10);
        },
        RARE
      )
    },
    {
      "regeneration",
      Item(
        "regeneration", 
        []() {
          unsigned short int count = 7 - Shop::rare_stock.at("regeneration");
          return 1.1 + (0.05 * count);
        },
        [](Item* item) {
          return "A recuperação de vida fica +" + to_string(static_cast<int>(round((item->upgrade() - 1.0) * 100.0))) + "% rápida";
        },
        [](Item* item) {
          Player::get()->regeneration *= item->upgrade();
        },
        []() {
          unsigned short int count = 7 - Shop::rare_stock.at("regeneration");
          return 30 + (count * 15);
        },
        RARE
      )
    },
    {
      "sentry_speed",
      Item(
        "sentry_speed", 
        []() {
          unsigned short int count = 4 - Shop::rare_stock.at("sentry_speed");
          return 1.2 + (0.1 * max(count - 1, 0));
        },
        [](Item* item) {
          return "Aumenta a velocidade de disparo das sentinelas em +" + to_string(static_cast<int>(round((item->upgrade() - 1.0) * 100.0))) + "%";
        },
        [](Item* item) {
          Sentry::attack_speed *= item->upgrade();
        },
        []() {
          unsigned short int count = 4 - Shop::rare_stock.at("sentry_speed");
          return 40 + (count * 20);
        },
        RARE
      )
    },
    {
      "ammo_consume",
      Item(
        "ammo_consume", 
        []() {
          return 0.2;
        },
        [](Item* item) {
          return "Ganha " + to_string(static_cast<int>(item->upgrade() * 100)) + "% de chance de não consumir bala do pente (inclui sentinelas)";
        },
        [](Item* item) {
          Player::get()->not_consume_ammo_chance = item->upgrade();
          Sentry::not_consume_ammo_chance = item->upgrade();
        },
        []() {
          return 120;
        },
        EPIC
      )
    },
    {
      "friendly_fire",
      Item(
        "friendly_fire", 
        []() {
          return 0;
        },
        [](Item* _) {
          (void)_;
          return "Disparos contra a própria base não causam mais dano";
        },
        [](Item* _) {
          (void)_;
          Base::friendly_fire = false;
        },
        []() {
          return 100;
        },
        EPIC
      )
    },
    {
      "ricochet",
      Item(
        "ricochet", 
        []() {
          return 0;
        },
        [](Item* _) {
          (void)_;
          return "Balas ricocheteadas causam dano aos inimigos";
        },
        [](Item* _) {
          (void)_;
          Base::vengeful_bullets = true;
        },
        []() {
          return 140;
        },
        EPIC
      )
    }
  };
};