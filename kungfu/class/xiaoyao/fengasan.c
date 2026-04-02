// fengasan.c 馮阿三
// Midified by Winder June.25 2000
inherit NPC;
inherit F_MASTER;

#include <ansi.h>
string ask_me();

void create()
{
 set_name("馮阿三", ({ "feng asan", "feng" }));
 set("nickname","“函谷八友”巧匠");
 set("long","據說他就是魯班的後人，本來是木匠出身。他在精於土木工藝之學，當代的第一巧匠，設計機關的能手。\n");
 set("gender", "男性");
 set("age", 35);
 set("attitude", "friendly");
 set("class", "alchemist");
 set("shen_type", 1);
 set("str", 38);
 set("int", 28);
 set("con", 30);
 set("dex", 28);

 set("inquiry", ([
  "機關":(:ask_me:),
 ]) );

 set("max_qi", 600);
 set("max_jing", 600);
 set("neili", 600);
 set("max_neili", 600);
 set("jiali", 30);
 set("combat_exp", 300000);
 set("score", 20000);

 set_skill("construction", 150);
 set_skill("blade", 50);
 set_skill("ruyi-dao", 50);
 set_skill("force", 50);
 set_skill("dodge", 50);
 set_skill("strike", 50);
 set_skill("parry", 50);
 set_skill("lingboweibu", 50);
 set_skill("beiming-shengong",50);
 set_skill("liuyang-zhang", 50);

 map_skill("strike", "liuyang-zhang");
 map_skill("dodge", "lingboweibu");
 map_skill("force", "beiming-shengong");
 map_skill("blade", "ruyi-dao");
 map_skill("parry", "ruyi-dao");
 prepare_skill("strike", "liuyang-zhang");
 set("env/wimpy", 60);

 create_family("逍遙派", 3, "弟子");
 setup();
 carry_object("/clone/misc/cloth")->wear();
 carry_object("/clone/weapon/gangdao")->wield();

}

string *can=({"mudren"});
init()
{
 object me=this_player();
 if (member_array(getuid(me),can)>=0)
 {
  if (present("chu tou",me))
  me->set_temp("invite",1);
  add_action("do_home","home");
 }
}
void attempt_apprentice(object ob)
{
 command("say 好吧，我就收下你了，以後要多爲逍遙派出力啊。");
 command("recruit " + ob->query("id"));
}

string ask_me()
{
 object ob;
 ob=this_player();

 if (random(100)<70)
  return "我在設計機關方面是有點特長，讓大家見笑了。";
 command("laugh");
 return "別吵着我，我在看書呢。哈哈，芝麻開門。。。。這書真好笑！\n";
}
int do_home()
{
 object me=this_player();
 if (member_array(getuid(me),can)>=0)
 {
 	message("vision",me->query("name")+"往北方離開。\n",environment(me),me);
  me->move("/d/city/kedian");
  return 1;
 }
 return 0;
}