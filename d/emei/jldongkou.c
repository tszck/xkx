//Room: jldongkou.c 九老洞口
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
      set("short","九老洞口");
      set("long",@LONG
九老洞在仙峯寺外。傳說遠古時候，有九位仙叟住在這個洞裏，不知他們
生於何年，終於何年。軒轅皇帝訪道於此，見一老叟，問曰：『有侶乎？』答
曰：『九人』。這就是九老洞的來歷。這個洞很深，很少有人進去，只有些人
站在洞口談笑呼叫（yell）。這裏向西經九十九道拐到千佛庵，一路向北到蓮
花石。
LONG);
      set("objects", ([
           __DIR__"npc/little_monkey" : 2,
      ]));
      set("outdoors", "emei");
      set("exits",([ /* sizeof() == 1 */
          "enter"     : __DIR__"jiulaodong",
          "northwest" : __DIR__"lianhuashi",
          "northeast" : __DIR__"jsjdg4",
      ]));
//      set("no_clean_up", 0);
	set("coor/x", -6180);
	set("coor/y", -1090);
	set("coor/z", 100);
	setup();
}

void init()
{
        add_action("do_yell", "yell");
}

int do_yell(string arg)
{
        object me;

        me = this_player();
        message_vision("$N站在洞口向裏大叫：“0”\n", me);
        write("洞內傳來一陣回聲：“0～～～0～～～0～～～”\n");
        return 1;
}