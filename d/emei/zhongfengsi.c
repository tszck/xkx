//Room: zhongfengsi.c 中峯寺
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
      set("short","中峯寺");
      set("long",@LONG
中峯寺在白雲峯下，始建於晉代，原為道觀。傳説觀內的道人每年在三月
三日都獻身給山中一條大蟒，以為可以昇仙。後來有個從資州來的明果禪師，
殺了那條大蟒，道士們始知上當，感激不已，自願改信佛教，從此改觀為寺。
這裏往北可到清音閣，東下至神水庵。
LONG);
      set("objects", ([
               __DIR__+"npc/guest": 1,
      ]));
      set("exits",([ /* sizeof() == 1 */
          "northwest"    : __DIR__"qingyinge",
          "eastdown"     : __DIR__"shenshuian",
      ]));
      set("outdoors", "emei");
//      set("no_clean_up", 0);
	set("coor/x", -6110);
	set("coor/y", -1040);
	set("coor/z", 80);
	setup();
      replace_program(ROOM);
}