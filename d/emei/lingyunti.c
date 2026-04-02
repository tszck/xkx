//Room: lingyunti.c 凌雲梯
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
      set("short","凌雲梯");
      set("long",@LONG
這是凌雲梯，最早是一位叫阿婆多的外國和尚在此縛木架石，以渡行人，
又叫「胡僧梯」。路邊有梅子坡，可見滿坡青梅如豆，於疏枝密葉中逗引行人，
甚有「望梅止渴」之功用。此梯北通洗象池，南至雷洞坪。
LONG);
      set("outdoors", "emei");
      set("exits",([ /* sizeof() == 1 */
          "northdown"  : __DIR__"xixiangchi",
          "southup"    : __DIR__"leidongping",
      ]));
      set("no_clean_up", 0);
	set("coor/x", -6220);
	set("coor/y", -1090);
	set("coor/z", 140);
	setup();
      replace_program(ROOM);
}