//Room: hcaxiuxishi.c 華藏庵休息室
//Date: Oct. 2 1997 by That

inherit ROOM;
void create()
{
      set("short","華藏庵休息室");
      set("long",@LONG
這裏是峨嵋華藏庵的休息室。窗簾拉下來，房裏整整齊齊放了很多木牀。
有幾個夜晚守庵的小師太正在睡覺。
　　休息室外就是禪房。
LONG);
      set("exits",([ /* sizeof() == 1 */
          "north" : __DIR__"hcachanfang", 
      ]));
      set("sleep_room", 1);
      set("no_clean_up", 0);
	set("coor/x", -6210);
	set("coor/y", -1200);
	set("coor/z", 190);
	setup();
      replace_program(ROOM);
}
