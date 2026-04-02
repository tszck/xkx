//Room: jldongnei.c 九老洞
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
      set("short","九老洞");
      set("long",@LONG
這就是峨嵋第一大洞，洞內深窈無比，神祕難測。你一走進來，便發覺洞
中叉叉洞多如迷宮，怪異莫測，似乎黝黑無底。洞裏隱隱傳來雞犬鼓樂之聲，
令人驚異間，忽有蝙蝠羣湧而至，撲熄火炬。還是快快離開吧。
LONG);
      set("objects", ([
           __DIR__"npc/poorman" : 2,
           __DIR__"npc/little_monkey" : 3,
           __DIR__"npc/bat" : 4,
      ]));
      set("no_clean_up", 0);
	set("coor/x", -6170);
	set("coor/y", -1100);
	set("coor/z", 100);
	setup();
}
void init()
{
        add_action("do_leave", "leave");
}

int do_leave(string arg)
{
        object me;
        object *inv;
	int i;
        me = this_player();
        inv = all_inventory(environment(me));
        for (i = 0; i < sizeof(inv); i++)
        {
          if (inv[i]->is_character())
             {
              inv[i]->move(__DIR__"jiulaodong");
             }
        } 
//        me->move(__DIR__"jiulaodong");
        return 1;
}