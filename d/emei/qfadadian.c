//Room: qfadadian.c 千佛庵大殿
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
      set("short","千佛庵大殿");
      set("long",@LONG
千佛庵殿宇高廣宏闊，清潔莊嚴。庵內有一具七萬千佛蓮燈，有紋龍七條
環於燈體，並有佛像數百周匝排列，雕縷精緻無比。
LONG);
      set("objects", ([
           CLASS_D("emei") + "/hui" : 1,
           CLASS_D("emei") + "/wenyin" : 1,
      ]));
      set("exits",([ /* sizeof() == 1 */
          "out"      : __DIR__"qianfoan",
          "east"     : __DIR__"qfachanfang",
      ]));
//      set("no_clean_up", 0);
	set("coor/x", -6130);
	set("coor/y", -1070);
	set("coor/z", 80);
	setup();
      replace_program(ROOM);
}