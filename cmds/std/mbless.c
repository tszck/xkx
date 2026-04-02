
inherit F_CLEAN_UP;

#include <ansi.h>


string *color = ({ RED, GRN, YEL, BLK, MAG, BLU, CYN, WHT, HIR, HIG, HIY, HIB, HIM, HIC, HIW});
string *color1 = ({ RED, GRN, YEL, MAG, BLU, CYN});

void input_number(string arg);
void show_emote(string* arg,string text);

string *pic = ({ @TEXT
        __   __
       /  \./  \/\_
   __{^\_ _}_   )  }/^\
  /  /\_/^\._}_/  //  /
 (  (__{(@)}\__}.//_/__A____A_______A_____A_____A_____A___A___A______
  \__/{/(_)\_}  )\\ \\---v-----V-----V---Y--v----Y----v---V-----v---
    (   (__)_)_/  )\ \>
     \__/     \__/\/\/
        \__,--'


TEXT,
@TEXT
 .        *                  . . . .  .   .  + .
            "You Are Here" .   .  +  . . .
.                 |      .  .   .    .    . .
                  |     .    .    . +.    +  .
                 \|/            .       .   . .
        . .       V          .    * . . .  .  +   .
           +     ☆           .   .      +
                            .       . +  .+. .
  .                      .     . + .  . .     .      .
           .      .    .     . .   . . .
      *             .    . .  +    .  .           .
          .     .    .  +   . .  *  .       .
               . + .  .  .  .. +  .
.      .  .  .  *   .  *  . +..  .            *
 .      .   . .   .   .   . .  +   .    .            +
TEXT,
@TEXT
 ..           .           .        .     .   .
  *     \     |   /               + . :      *   .            .    *
  .   ---   /    \   ---       .     .   . .     .     *       .
   .       | ~  ~ |        .        . . . .  .   .  + .
      ---   \__O_/   ---         :     .   .  +  . . .
     .      /  |    .  . .     . .   .   .   . .   +  .     +
   .   *  . .      . .    . .  +    .  ...     - O -. .
          .     . + .  .  .  .. +  ..       . / |
 ..      .  .  .  *   .  *  . +..  .            *
  .      .   . .   .   .   . .  +   .    .            +

  .      .   . .   .   .   . .  +   .    .            +

                                   .&______~*@*~______&.           *
                                 "w/%%%%%%%%%%%%%%%%%%%\w"        ***
      __/M__                    p-p_|__|__|_____|__|__|_q-q      **Y**
 ____|O_^_O|___________________[EEEEM==M==MM===MM==M==MEEEE]-__....|....

    ＤＯ ＹＯＵ ＦＥＥＬ ＴＨＥ ＬＯＶＥ ＴＯＮＩＧＨＴ？
TEXT,
@TEXT

             * *   * * *   * *
            *    *    *  *    *
        <========     *==     *==<<<<<<
             *       *       *
               *   *   *   *
                 *       *


TEXT,
@TEXT
            ...  :``..':
             : ````.'   :''::'
           ..:..  :     .'' :
        ``.    `:    .'     :
            :    :   :        :
             :   :   :         :
             :    :   :        :
              :    :   :..''''``::.
               : ...:..'     .''
               .'   .'  .::::'
              :..'''``:::::::
              '         `::::
                          `::.
                           `::
                            :::.
                 ..:```.:'`. ::'`.
               ..'      `:.: ::
              .:        .:``:::
              .:    ..''     :::
               : .''          ::
                :             ::
                               :
                               :
                               :
                               :
                               :
                               .

TEXT,
@TEXT
         .     .                                   .     .
    ...  :``..':                              ...  :``..':
     : ````.'   :''::'                         : ````.'   :''::'
   ..:..  :     .'' :                        ..:..  :     .'' :
``.    `:    .'     :                     ``.    `:    .'     :
    :    :   :        :                       :    :   :        :
     :   :   :         :                       :   :   :         :
     :    :   :        :                       :    :   :        :
      :    :   :..''''``::.                     :    :   :..''''``::.
       : ...:..'     .''                         : ...:..'     .''
       .'   .'  .::::'                           .'   .'  .::::'
      :..'''``:::::::                           :..'''``:::::::
      '         `::::                           ,         `::::
                  `::.                                      `::.
                   `::                                       `::
                    :::.                                      :::.
         ..:```.:'`. ::'`.                         ..:```.:'`. ::'`.
       ..'      `:.: ::                          ..'      `:.: ::
       ..'      `:.: ::                          ..'      `:.: ::
      .:        .:``:::                         .:        .:``:::
      .:    ..''     :::                        .:    ..''     :::
       : .''         .::                         : .''         .::
        :          .'`::                          :          .'`::
                       ::                                        ::
                       ::                                        ::
                        :                                         :
                        :                                         :
                        :                                         :
TEXT,
@TEXT

                      .      .'
                       :`...' `.,'  '
                   `.  ' .**.  ; ; ':
                   ` ``:`****,'  .' :
                 ..::.  ``**":.''   `.
               .:    `: ; `,'        :
                 `:    `   :         ;
                   :   :   :        ;
                   :    :   :     .:
                    :    :   :..,'  ``::.
                     `....:..'  ..:;''
                     .:   . ...::::
                    ,'''''``:::::::
                              `::::
                                `::.
                                 `::
                          . ,.    ::::'      ,..
                        .'.'  ``.  ::      .'.. `.
                       '        .: ::    ,'.'     .
                     .' ,'    .::::::   ,.'    .:::.
                   .' .'  ..:'     ::: .,   .;'     ~
                  ,;::;.::''        ::.:..::'
                 ~                  ::;'
                 ~                  ::;'
                                    ::
                                  ,:::
                                    ::.
                                    `::
                                     ::
                                     ::
                                     ::
                                     ::
TEXT, });

int main(object me,string arg)
{
	object male, female, env;
	string id1, id2, name1, name2;

	env = environment(me);

	if( !arg || sscanf(arg, "%s with %s", id1, id2) != 2 )
		return notify_fail("指令格式：mbless MALE with FEMALE\n");

	if(!objectp(male = present(id1, environment(me))) ||
		!objectp(female = present(id2, environment(me))))
		return notify_fail("這裏沒有這兩個人哦~~~\n");

	if ( ! living( male ) || ! living (female) )
		return notify_fail("看清楚點，那不是活的。\n");
	if(( male->query("gender")!="男性" && male->query("gender")!="雄性") ||
	(female->query("gender")!="女性" && female->query("gender")!="雌性"))
		return notify_fail("老兄，不要錯點鴛鴦哦~\n");

	name1 = male->query("name");
	name2 = female->query("name");

	if ((me->query("qi")<100) || (me->query("jing")<100) ||
		(me->query("neili")<100))
		return notify_fail("你沒有精神祝福人家了！\n");
	me->set("qi",10);
	me->set("jing",10);
	me->set("neili",10);

	message_vision(CYN"$N虔誠地雙手合十，默默地祈禱道：愛神呀，請賜予"+name1+"和"+name2+CYN"幸福吧！願他們會\n永遠相親相愛，互相扶持，愛火永不熄滅！\n",me);
	call_out("show_picture", 2 + random( 3 ), name1, name2);
	return 1;
}

void show_picture(string name1, string name2)
{
	string str;
	str = GRN"只聽見東方轟隆隆地響了一聲，一個姣美的女聲響起：\n\t"HIM+name1+BLU"和"HIM+name2+BLU"將在我的庇護下永遠\n幸福！我以愛神的名義起誓！\n\n\n"NOR;
	message("vision",str, users());
	call_out("show_flower", 2, name1, name2);
}

void show_flower(string name1, string name2)
{
	string str;
	str = "天空中突然閃出一道絢麗的火花，一個巨大的圖案逐漸\n顯現：\n";
	str += color1[random(sizeof(color1))]+pic[random(sizeof(pic))]+NOR;
	str += YEL"四下裏隱隱傳來眾人深沉的祝福聲：\n     “"HIM+name1+YEL"和"HIM+name2+YEL"永遠幸福...\n                                           永遠幸福！！”\n\n\n";
	message("vision", str, users());
	if ( random( 2) )
		call_out( "show_flower",2 + random ( 3 ),name1,name2 );
}
int help(object me)
{
	write(@HELP
指令格式 : mbless <男名> with <女名>

    這個指令可以讓你衷心祝賀一些喜事。

HELP
	);
	return 1;
}

