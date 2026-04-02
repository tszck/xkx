//Room: haohanpo.c 好漢坡
//Date: Sep 22 1997

inherit ROOM;

void create()
{
      set("short","好漢坡");
      set("long",@LONG
此處連綿十幾裏山勢陡峭，名為好漢坡，山路兩旁種滿了細竹，翠
色橫空景象怡人，不知不覺讓你忘記了爬坡的疲勞。坡頂有一座回龍觀，
是展望嶽頂的最佳去處，但見天柱峯青紫插天，如在眼前，而相去實際
上還有五十里。
LONG);
      set("exits",([ /* sizeof() == 1 */
          "northdown": __DIR__"wdbl",
          "southdown": __DIR__"shanlu1",
      ]));
      set("outdoors", "wudang");
      set("no_clean_up", 0);
	set("coor/x", -2050);
	set("coor/y", -840);
	set("coor/z", 60);
	setup();
      replace_program(ROOM);
}
