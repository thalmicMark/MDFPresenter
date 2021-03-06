/*
 The MIT License (MIT)
 
 Copyright (c) 2013 Mark DiFranco
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 */

//
//  FPPresenter.h
//  MDFPresenter
//
//  Created by Mark DiFranco on 2013-02-27.
//
//

#import <UIKit/UIKit.h>

typedef void (^BasicBlock)(void);

typedef enum {
   FPPresentationStylePresentFade,
   FPPresentationStylePresentModal,
   FPPresentationStyleDismiss,
   FPPresentationStyleDismissAll
} FPPresentationStyle;

//==========================================================
// - MDFPresentingObject
//==========================================================

@interface MDFPresentingObject : NSObject

@property (nonatomic, retain) UIViewController *viewController;
@property (nonatomic, readwrite) BOOL animated;
@property (nonatomic, readwrite) FPPresentationStyle presentationStyle;
@property (nonatomic, copy) BasicBlock completion;

+ (MDFPresentingObject*)objectWithViewController:(UIViewController*)viewController animation:(BOOL)animation presentationStyle:(FPPresentationStyle)style completion:(BasicBlock)completion;

@end

//==========================================================
// - MDFPresenter
//==========================================================

@interface MDFPresenter : NSObject

+ (MDFPresenter*)instance;
+ (BOOL)hasModalOpen;

+ (UIView*)topView;
+ (UIViewController*)topModalViewController;
+ (void)presentModalViewControllerInNavigationController:(UIViewController*)viewController animated:(BOOL)aniamted completion:(BasicBlock)completion;
+ (void)presentModalViewController:(UIViewController*)viewController animated:(BOOL)animated completion:(BasicBlock)completion;
+ (void)dismissModalViewControllerAnimated:(BOOL)animated completion:(BasicBlock)completion;
+ (void)dismissAllModalViewControllersAnimated:(BOOL)animated completion:(BasicBlock)completion;

@end


