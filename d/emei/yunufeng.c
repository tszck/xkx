//Room: yunufeng.c 玉女峯
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
      set("short","玉女峯");
      set("long",@LONG
這是歸雲閣邊的玉女峯，峯頂有一個四尺見方的小池，深亦四尺，四季不
枯，傳為天女沐浴之器。古時州刺史馮楫，曾在此結茅而居，發奮誦讀《華嚴
經》，不食人間煙火，於是玉女下凡，為他饋贈食物。
LONG);
      set("objects", ([
           CLASS_D("emei") + "/fang" : 1,
           "/clone/medicine/vegetable/fangfeng" : random(2),
      ]));
      set("exits",([ /* sizeof() == 1 */
          "northdown"  : __DIR__"guiyunge",
      ]));
      set("outdoors", "emei");
	set("coor/x", -6080);
	set("coor/y", -1050);
	set("coor/z", 60);
	setup();
      replace_program(ROOM);
}