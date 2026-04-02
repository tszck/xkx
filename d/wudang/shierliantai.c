//Room: shierliantai.c 十二蓮臺
//Date: Sep 22 1997

inherit ROOM;

void create()
{
      set("short","十二蓮臺");
      set("long",@LONG
這裏是武當絕頂的十二蓮臺，臺與臺之間以曲欄相連，雕刻精美，
是遠眺的最佳所在。站立此臺四眺，宛如身在千葉寶蓮之上，千峯萬壑
都在腳下。往西可望到七百里外的華山，東望則漢水如練，襄、樊一帶
盡收眼底。
LONG);
      set("exits",([ /* sizeof() == 1 */
          "east"     : __DIR__"jinding",
      ]));
      set("objects", ([
          "/clone/medicine/vegetable/huoxiang" : random(2),
      ]));
      set("outdoors", "wudang");
	set("coor/x", -2040);
	set("coor/y", -1040);
	set("coor/z", 180);
	setup();
      replace_program(ROOM);
}
