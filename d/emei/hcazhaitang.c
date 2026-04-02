//Room: hcazhaitang.c 華藏庵齋堂
//Date: Oct. 2 1997 by That

inherit ROOM;
string* names = ({
        __DIR__"obj/mala-doufu",
        __DIR__"obj/bocai-fentiao",
        __DIR__"obj/shanhu-baicai",
        __DIR__"obj/liuli-qiezi",
});

void create()
{
      set("short","華藏庵齋堂");
      set("long",@LONG
這裏便是峨嵋華藏庵的齋堂。齋堂裏擺滿了長長的餐桌和長凳，幾位小
師太正來回忙碌着佈置素齋。桌上擺了幾盆豆腐，花生，青菜以及素鴨等美
味素食。齋堂後面有一道門通往華藏庵儲物間，北邊的走廊通向廣場。
LONG);
      set("exits",([ /* sizeof() == 1 */
          "south" : __DIR__"chuwujian", 
          "north" : __DIR__"hcaeast2", 
      ]));

      set("objects",([
           __DIR__"obj/qingshui-hulu" : 1,
           names[random(sizeof(names))]: 1,
           names[random(sizeof(names))]: 1,
           names[random(sizeof(names))]: 1,
      ]));
//      set("no_clean_up", 0);
	set("coor/x", -6190);
	set("coor/y", -1190);
	set("coor/z", 190);
	setup();
      replace_program(ROOM);
}