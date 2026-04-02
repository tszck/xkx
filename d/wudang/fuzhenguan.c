//Room: fuzhenguan.c 復真觀五層樓
//Date: Sep 22 1997

inherit ROOM;

void create()
{
      set("short","復真觀五層樓");
      set("long",@LONG
復真觀五層樓構造奇特，其間有十二根梁枋交叉重疊，下面僅用一
柱支撐，即有名的“一柱十二梁”。在這裏俯瞰羣山，煙雲迷離，遠望
金頂，一柱擎天，為觀景勝地。
LONG);
      set("exits",([ /* sizeof() == 1 */
          "west"     : __DIR__"taizipo",
      ]));
      set("objects",([ /* sizeof() == 1 */
          "/clone/medicine/vegetable/mahuang" : random(2),
      ]));
      set("outdoors", "wudang");
	set("coor/x", -2040);
	set("coor/y", -860);
	set("coor/z", 60);
	setup();
      replace_program(ROOM);
}
