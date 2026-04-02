#include <ansi.h>

nosave string dest_addr;
void icheck(string address);
void report(string address,int middle);
string compare(string address,int middle);
mapping before, after;
int usertime;
object me=previous_object(1);

int connect_to(string arg)
{
      	dest_addr=arg;
        if (sscanf(dest_addr, "%*d.%*d.%*d.%*d") == 4)
          icheck(arg);
        else
         {
         	write("嘗試解析地址...如長時間沒有回潰，請指定ip查詢\n");
          resolve(dest_addr, "resolve_callback");
          return 1;
        }
}

void resolve_callback(string address, string resolved, int key)
{
        
        if (! resolved)
           {
           	//不會了 怎麼才能顯示
           	write("失敗\n");
             	tell_object(previous_object(2),"無法解析地址 "+address+" 。\n");
              if (sscanf(dest_addr, "%*d.%*d.%*d.%*d") == 4)
                  resolved = dest_addr;
              else if (sscanf(dest_addr, "%*d.%*d.%*d") == 3)
                  resolved = dest_addr+".0";
              else if (sscanf(dest_addr, "%*d.%*d") == 2)
                  resolved = dest_addr+".0.0";
              else return;
           }
        icheck(resolved);
}

void icheck(string address)
{
  int add1,add2,add3,add4;
  int read_from=0;
  int read_to=167379; //目前總共167380行 這個怎麼用函數來自動賦值？
  int middle;
  before = rusage();
  sscanf(address,"%d.%d.%d.%d",add1,add2,add3,add4);
  if (add1 > 255 || add1 < 0 
    ||add2 > 255 || add2 < 0 
    ||add3 > 255 || add3 < 0
    ||add4 > 255 || add4 < 0)
    { tell_object(me,"輸入地址錯誤，請核實\n"); return;}
  while ( read_from <= read_to )
  {
  	middle = (read_from + read_to) /2;
    switch(compare(address,middle))
    {
    	case "包含":
    		 report(address,middle);
    		 return;
      case "大於":  
      	 read_from = middle+1;
         break;
      case "小於": 
         read_to   = middle-1;
         break;
    }
  }
  tell_object(me,"無法找到匹配數據。\n");
  return ;
}

string compare(string address,int middle)
{
	  string line;
 	  string from,to;
    int  add1, add2, add3, add4;
 	  int from1,from2,from3,from4;
 	  int   to1,  to2,  to3,  to4;

 	  line=read_file("/data/ipdata.o",middle,1);
    from = line[0..15];
    to   = line[16..31];
    sscanf(address,"%d.%d.%d.%d", add1, add2, add3, add4);
    sscanf(from   ,"%d.%d.%d.%d",from1,from2,from3,from4);
    sscanf(to     ,"%d.%d.%d.%d",  to1,  to2,  to3,  to4);
    if (add1 < from1 )   return "小於";
    else if (add1 > to1) return "大於";
    else if (add1 < to1) return "包含";
    else //   add1 == to1
    if (add2 < from2)    return "小於";
    else if (add2 > to2) return "大於";
    else if (add2 < to2) return "包含";
    else // add1 == to1  && add2 == to2
    if (add3 < from3)    return "小於";
    else if (add3 > to3) return "大於";
    else if (add3 < to3) return "包含";
    else // add1 == to1 && add2 == to2 && add3 == to3
    if (add4 < from4)    return "小於";
    else if (add4 > to4) return "大於";
    else if (add4 < to4) return "包含";
    else //add1 == to1 && add2 == to2 && add3 == to3 && add4 == to4
       return "包含";
}

void report(string address,int middle)
{
	string line=read_file("/data/ipdata.o",middle,1);
	if (!stringp(address)) tell_object(me,"沒有找到相應數據a\n");
	if (!stringp(line))    tell_object(me,"沒有找到相應數據b\n");
  tell_object(me,sprintf(HIC"查詢地址%s：\n對應物理地址為："YEL"%s\n"NOR,address,line[32..sizeof(line)]));
  after = rusage();
  usertime = after["utime"] - before["utime"];
  tell_object(me,sprintf("此次查找花費時間為%d 微秒\n",usertime ));
}