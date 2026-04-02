//Room: gudelin1.c 古德林
//Date: Oct. 2 1997 by That

inherit ROOM;
string look_shibei();

void create()
{
      set("short","古德林");
      set("long",@LONG
這是一片密密的楠木林，株株秀挺俊拔，枝葉分披上捧，如兩手擁佛，據
説有七萬株之多，要是不熟悉地形很容易迷路。林中有一片空地，幾隻楠木樁
排成梅花模樣。
LONG);
      set("outdoors", "emei");
      set("exits",([ /* sizeof() == 1 */
          "south"     : __DIR__"bailongdong",
          "southeast" : __DIR__"gudelin2",
          "southwest" : __DIR__"gudelin2",
          "northeast" : __DIR__"gudelin2",
          "northwest" : __DIR__"gudelin2",
      ]));
      set("objects", ([
              "/clone/medicine/vegetable/danggui" : random(2),
      ]));
	set("coor/x", -6120);
	set("coor/y", -1070);
	set("coor/z", 50);
	setup();
      replace_program(ROOM);
}