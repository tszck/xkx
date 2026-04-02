//Room: hcachanfang.c 華藏庵禪房
//Date: Oct. 2 1997 by That

inherit ROOM;
void create()
{
      set("short","華藏庵禪房");
      set("long",@LONG
這裏便是峨嵋華藏庵的禪房。地下散亂地放着許多蒲團，木魚等，此處
正是本派弟子打坐修行之所。幾位年輕師太和俗家女弟子正肅容入定。
　　禪房後面有一道門通往華藏庵休息室，北邊的走廊通向廣場。
LONG);
      set("exits",([ /* sizeof() == 1 */
          "north" : __DIR__"hcawest2", 
          "south" : __DIR__"hcaxiuxishi", 
      ]));
      set("sleep_room", 1);
      set("no_fight", 1);
      set("no_clean_up", 0);
	set("coor/x", -6210);
	set("coor/y", -1190);
	set("coor/z", 190);
	setup();
      replace_program(ROOM);
}