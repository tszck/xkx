//Room: cangjingge.c 藏經閣
//Date: Oct. 2 1997 by That

inherit ROOM;
void create()
{
      set("short","藏經閣");
      set("long",@LONG
小閣樓上便是峨嵋派的藏經閣了。這裏都是密密麻麻，高及頂棚的書架。
窗口下有一張大桌子，桌上放了幾本佛經。有個小師太正在向靜道師太借書。
LONG);
      set("objects", ([
           CLASS_D("emei") + "/dao" : 1,
           __DIR__"obj/fojing1"+random(2) : 1,
           __DIR__"obj/fojing2"+random(2) : 1,
      ]));

      set("exits",([ /* sizeof() == 1 */
          "down"  : __DIR__"chuwujian", 
      ]));
//      set("no_clean_up", 0);
	set("coor/x", -6190);
	set("coor/y", -1200);
	set("coor/z", 200);
	setup();
}
int valid_leave(object me, string dir)
{
     if ((dir == "south") && ( present("shu", me))
          && objectp(present("jingdao", environment(me))))
     {
         return notify_fail
                ("靜道師太見你想把經書拿走，上前輕聲說道：本閣經書不外借。\n");
     }
     return ::valid_leave(me, dir);
}