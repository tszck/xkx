//Room: heilong2.c 黑龍江棧道
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
      set("short","黑龍江棧道");
      set("long",@LONG
黑龍江棧道沿黑龍江而建。這裏一山中開，兩崖並立，形成一道寬僅數尺，
長達幾百米的深峽——白雲峽。黑龍江棧道就從狹窄的白雲峽中轉折穿過，架
設在絕壁上。走在棧道上，只覺道窄人危；俯視深澗，急流飛旋，山靜而覺動；
仰觀頭頂，天光如隙，崖開而欲合。這就是天開畫圖的「一線天」。棧道南通
千佛庵，北至清音閣。
LONG);
      set("outdoors", "emei");
      set("exits",([ /* sizeof() == 1 */
          "south"    : __DIR__"qianfoan",
          "north"    : __DIR__"heilong1",
      ]));
      set("objects", ([
          "/clone/medicine/vegetable/gancao" : random(2),
      ]));
	set("coor/x", -6130);
	set("coor/y", -1050);
	set("coor/z", 80);
	setup();
      replace_program(ROOM);
}