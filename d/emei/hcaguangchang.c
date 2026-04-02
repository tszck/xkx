//Room: hcaguangchang.c 華藏庵廣場
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
      set("short","華藏庵廣場");
      set("long",@LONG
這裏是峨嵋華藏庵的廣場，地上鋪着青磚。正前方有一道臺階，通往大
雄寶殿。殿前有個丈許高的大香爐，香爐前的香臺上，紅燭高燒，香菸飄繞。
廣場上有幾個小師太正在練功。自此左右各有一條走廊通向後殿。
LONG);
      set("objects", ([
           CLASS_D("emei") + "/xu" : 1,
           CLASS_D("emei") + "/first" : 1,
      ]));
      set("outdoors", "emei");
      set("exits",([ /* sizeof() == 1 */
          "north"   : __DIR__"hcazhengdian", 
          "southup" : __DIR__"hcadadian", 
          "west"    : __DIR__"hcawest1", 
          "east"    : __DIR__"hcaeast1", 
      ]));
      set("valid_startroom","1");
//      set("no_clean_up", 0);
	set("coor/x", -6200);
	set("coor/y", -1170);
	set("coor/z", 190);
	setup();
      replace_program(ROOM);
      "/clone/board/emei_b"->foo();
}