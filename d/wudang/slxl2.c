//Room: slxl2.c 松林小路
//Date: Sep 22 1997

inherit ROOM;

string look_shibei();

void create()
{
      set("short","松林小路");
      set("long",@LONG
這是山腳松林中的小路，兩邊長滿參天的紅松樹，只能看見一線天
空。路旁有道士在奮力砍樹。東邊可回大道。
    路邊有個石碑(shibei)，很多遊客在圍那裏。原來西邊上去就是名
震天下的解劍巖了，
LONG);
      set("outdoors", "wudang");
      set("item_desc", ([
          "shibei" : (: look_shibei :),
      ]));
      set("exits",([ /* sizeof() == 1 */
          "westup" : __DIR__"jiejianyan",
          "east"   : __DIR__"slxl1",
          "south"  : __DIR__"songlin1",
          "north"  : __DIR__"songlin2",
      ]));
      set("no_clean_up", 0);
	set("coor/x", -2020);
	set("coor/y", -800);
	set("coor/z", 0);
	setup();
}

string look_shibei()
{
        return
        "**************************************************\n"
        "********　        　　　　　　　　　　　　********\n"
        "********　        　武當派通告    　　　　********\n"
        "********　                            　　********\n"
        "********　    往前就是武當山解劍巖。所有　********\n"
        "********　外來人客請自覺解劍。邪魔外道到　********\n"
        "********　此止步。                　　　　********\n"
        "********　　　　　                　　　　********\n"
        "**************************************************\n";
}
