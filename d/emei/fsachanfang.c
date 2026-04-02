//Room: fsachanfang.c 禪房
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
      set("short","福壽庵禪房");
      set("long",@LONG
這裏是一間安靜寬敞的禪房，乃是福壽庵中弟子打坐修行之所。地下整整
齊齊地放着許多蒲團。幾位年輕師太和俗家女弟子正肅容入定。
LONG);
      set("exits",([ /* sizeof() == 1 */
          "west"    : __DIR__"lingwenge",
      ]));
      set("sleep_room", 1);
      set("no_clean_up", 0);
      set("no_fight", 1);
	set("coor/x", -6090);
	set("coor/y", -1060);
	set("coor/z", 70);
	setup();
      replace_program(ROOM);
}