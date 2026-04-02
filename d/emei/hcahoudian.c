//Room: hcahoudian.c 華藏庵後殿
//Date: Oct. 2 1997 by That

inherit ROOM;
void do_chat();

void create()
{
      set("short","華藏庵後殿");
      set("long",@LONG
這是峨嵋山華藏庵的後殿。是峨嵋派掌門人傳教弟子功夫的地方。這裏
供有一尊普賢菩薩像。兩旁靠牆放着幾張太師椅，地上放着幾個蒲團。掌門
人正在向幾個女弟子傳授武功。
LONG);
      set("objects", ([
           CLASS_D("emei") + "/miejue" : 1,
      ]));
      set("no_get_from", 1);
      set("no_get", 1);
      set("no_steal", 1);
      set("no_clean_up", 0);
      set("exits",([ /* sizeof() == 1 */
          "north" : __DIR__"hcadadian", 
          "out"   : __DIR__"yhrkou", 
      ]));
	set("coor/x", -6200);
	set("coor/y", -1190);
	set("coor/z", 200);
	setup();
      replace_program(ROOM);
}