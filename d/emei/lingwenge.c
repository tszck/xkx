//Room: lingwenge.c 靈文閣
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
      set("short","靈文閣");
      set("long",@LONG
這裏是福壽庵的靈文閣，是主持靜照師太傳授佛法的地方。兩名青衣小尼
隨侍在旁，似乎在聆聽師太的教晦。閣內佈置簡陋，靠牆放着幾把竹椅，地上
放着幾個蒲團。東首有一禪房。西面是一個齋廳。
LONG);
      set("objects", ([
           CLASS_D("emei") + "/zhao" : 1,
      ]));
      set("exits",([ /* sizeof() == 1 */
          "out"     : __DIR__"fushouan",
          "east"    : __DIR__"fsachanfang",
          "west"    : __DIR__"fsazhaitang",
      ]));
//      set("no_clean_up", 0);
	set("coor/x", -6100);
	set("coor/y", -1060);
	set("coor/z", 70);
	setup();
      replace_program(ROOM);
}