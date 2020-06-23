//
//  JL_Tools.h
//  JL_BLEKit
//
//  Created by zhihui liang on 2018/11/9.
//  Copyright © 2018 www.zh-jieli.com. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef void(^JL_Action)(void);

@interface JL_Tools : NSObject

/**
 Data自定义截取。
 
 @param data 数据
 @param index 偏移
 @param length 长度
 @return 截取后的数据
 */
+(NSData*)data:(NSData*)data R:(NSInteger)index L:(NSInteger)length;

/**
 NSData 转成 10进制
 
 @param data 数据类型
 @return NSInteger类型
 */
+(NSInteger)dataToInt:(NSData*)data;

/**
 NSData 转成 NSString
 
 @param data 数据
 @return 字符串
 */
+(NSString*)dataChangeToString:(NSData*)data;

/**
 uint16_t 转成 NSData
 
 @param value uint16_t类型
 @param endian YES：小端  NO：大端
 @return NSData
 */
+(NSData*)uInt16_data:(uint16_t)value Endian:(BOOL)endian;

/**
 uint32_t 转成 NSData
 
 @param value uint32_t类型
 @param endian YES：小端  NO：大端
 @return NSData
 */
+(NSData*)uInt32_data:(uint32_t)value Endian:(BOOL)endian;

/**
 大小端转换

 @param data 数据
 @return 转换后的数据
 */
+(NSData*)changeBigOrSmall:(NSData*)data;

/**
 @"ffff0000" 转成 <ffff 0000>，16进制的字符串变成NSData。
 
 @param hex 类似@"ffff0000"
 @return NSData类型 => <ffff 0000>
 */
+(NSMutableData*)HexToData:(NSString*)hex;

/**
 求自然数：aByte ==> -2 -1 0 1 2 3...
 @param aByte 数据
 @return 自然数
 */
+(int)getNaturalNumber:(NSData*)aByte;
/**
 发出通知事件
 
 @param name 通知名字
 @param object 传递的对象
 */
+(void)post:(NSString*)name Object:(id __nullable)object;

/**
 监听通知事件
 
 @param name 通知名字
 @param action 实现方法
 @param own 监听者
 */
+(void)add:(NSString*__nullable)name Action:(SEL)action Own:(id)own;

/**
 取消通知监听
 
 @param name 通知名字
 @param own 监听者
 */
+(void)remove:(NSString*__nullable)name Own:(id)own;

/**
 往NSUserDefault存入对象（注意：可变类型对象不适用）。
 
 @param objc 对象
 @param key 键值
 */
+(void)setUser:(id)objc forKey:(NSString*)key;

/**
 从NSUserDefault取出对象（注意：可变类型对象不适用）。
 
 @param key 键值
 @return 返回对象
 */
+(id)getUserByKey:(NSString*)key;

/**
 移除NSUserDefault相对应的对象
 
 @param key 键值
 */
+(void)removeUserByKey:(NSString*)key;


/**
 延时执行block。
 
 @param sec 延时时间（秒）
 @param block 代码块
 */
+(void)delay:(double)sec Task:(JL_Action)block;

/**
 异步执行block。
 
 @param block 代码块
 */
+(void)subTask:(JL_Action)block;

/**
 主线程执行block。
 
 @param block 代码块
 */
+(void)mainTask:(JL_Action)block;


/**
 新建定时器
 
 @param sel 执行方法
 @param objc 执行对象
 @param sec 间隔时间（秒）
 @return NSTimer
 */
+(NSTimer*)timingStart:(SEL)sel target:(id)objc Time:(NSTimeInterval)sec;


/**
 暂停定时间器
 
 @param timer 定时器指针
 */
+(void)timingPause:(__weak NSTimer*)timer;

/**
 继续定时器
 
 @param timer 定时器指针
 */
+(void)timingContinue:(__weak NSTimer*)timer;


/**
 摧毁定时器
 
 @param timer 定时器指针
 */
+(void)timingStop:(__weak NSTimer*)timer;


/**
 在存在的文件路径上，建立新的文件。
 
 @param sPath 沙盒
 @param mPath 中间路径
 @param file 文件名
 @return 完成路径
 */
+(NSString*)createOn:(NSSearchPathDirectory)sPath
          MiddlePath:(NSString*)mPath
                File:(NSString*)file;

/**
 列出文件路径
 
 @param sPath 沙盒
 @param mPath 中间路径
 @param file 文件名
 @return 完整路径
 */
+(NSString*)listPath:(NSSearchPathDirectory)sPath
          MiddlePath:(NSString*)mPath
                File:(NSString*)file;

/**
 *  用途:【查找】一个文件，在你想要的路径下。
 *  @param   sPath     系统路径
 *  @param   mPath     中途路径    -->> @"test1/test2/test3" <<--
 *  @param   file      文件名
 */
+(NSString*)findPath:(NSSearchPathDirectory)sPath
          MiddlePath:(NSString*)mPath
                File:(NSString*)file;

/**
 删除文件
 
 @param path 完整路径
 @return 成功与否
 */
+(BOOL)removePath:(NSString*)path;

/**
 *  用途:解析JSON文件。
 *  @param   path      文件路径
 */
+(id)JsonPath:(NSString*)path;

/**
 *  NSArray ==> NSString.
 */
+(NSString*)arrayToJson:(NSArray *)array;

/**
 数据覆盖写进文件
 
 @param data 数据
 @param path 文件路径
 @return 成功与否
 */
+(BOOL)writeData:(NSData*)data fillFile:(NSString*)path;

/**
 数据写进文件的末端
 
 @param data 数据
 @param path 文件路径
 */
+(void)writeData:(NSData*)data endFile:(NSString*)path;

/**
 *  UNICODE 编码字符串(小端)
 */
+(NSString*)stringUnicode:(NSData*)data;

/**
 *  UNICODE 编码字符串(大端)
 */
+(NSString*)stringUnicodeBig:(NSData*)data;

/**
 *  ANSI 编码字符串
 */
+(NSString*)stringANSI:(NSData*)data;

/**
 *  GBK 编码字符串
 */
+(NSString*)stringGBK:(NSData*)data;

/**
 *  返回时间戳（单位：秒）
 */
+(long)dateCurrent;

@end

NS_ASSUME_NONNULL_END