//Room: hcadadian.c 華藏庵大雄寶殿
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
      set("short","大雄寶殿");
      set("long",@LONG
這是峨嵋山華藏庵的大雄寶殿。正中供奉着普賢菩薩。一羣青衣小師太
正在地上誦經。後面有道小門通往後殿。
LONG);
      set("exits",([ /* sizeof() == 1 */
          "northdown"  : __DIR__"hcaguangchang", 
          "south"      : __DIR__"hcahoudian", 
      ]));
      set("no_clean_up", 0);
	set("coor/x", -6200);
	set("coor/y", -1180);
	set("coor/z", 200);
	setup();
      replace_program(ROOM);
}