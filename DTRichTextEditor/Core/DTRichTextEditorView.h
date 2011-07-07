//
//  DTRichTextEditorView.h
//  DTRichTextEditor
//
//  Created by Oliver Drobnik on 1/23/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "DTAttributedTextView.h"
#import "DTAttributedTextContentView.h"

@class DTTextRange, DTTextPosition;
@class DTCursorView;
@class DTLoupeView;
@class DTTextSelectionView;

typedef enum
{
	DTDragModeCursor = 0,
	DTDragModeLeftHandle,
	DTDragModeRightHandle
} DTDragMode;


@interface DTRichTextEditorView : DTAttributedTextView <UITextInputTraits, UITextInput, DTAttributedTextContentViewDelegate, UIGestureRecognizerDelegate>
{
	NSMutableAttributedString *_internalAttributedText;
	
	id<UITextInputTokenizer> tokenizer;
	id<UITextInputDelegate> inputDelegate;
	NSDictionary *markedTextStyle;
	
	DTTextRange *_selectedTextRange;
	DTTextRange *_markedTextRange;
    
    UITextStorageDirection _selectionAffinity;
	
	// UITextInputTraits
	UITextAutocapitalizationType autocapitalizationType; // default is UITextAutocapitalizationTypeSentences
	UITextAutocorrectionType autocorrectionType;         // default is UITextAutocorrectionTypeDefault
	BOOL enablesReturnKeyAutomatically;                  // default is NO
	UIKeyboardAppearance keyboardAppearance;             // default is UIKeyboardAppearanceDefault
	UIKeyboardType keyboardType;                         // default is UIKeyboardTypeDefault
	UIReturnKeyType returnKeyType;                       // default is UIReturnKeyDefault (See note under UIReturnKeyType enum)
    BOOL secureTextEntry;                                // default is NO
	
  //  UITextSpellCheckingType spellCheckingType;
	
	UITapGestureRecognizer *tap;
    BOOL _editable;
	
	DTLoupeView *_loupe;
	DTCursorView *_cursor;
	DTTextSelectionView *_selectionView;
	
	DTDragMode _dragMode;
	
	UILongPressGestureRecognizer *longPressGesture;
}


@property(nonatomic,getter=isEditable) BOOL editable;

@property (nonatomic, copy) NSAttributedString *attributedText;

@property(nonatomic, assign) id<UITextInputDelegate> inputDelegate;
@property (nonatomic, copy) NSDictionary *markedTextStyle;
@property (nonatomic) UITextStorageDirection selectionAffinity;

@property (nonatomic, retain) DTCursorView *cursor;

// UITextInputTraits
@property(nonatomic) UITextAutocapitalizationType autocapitalizationType;
@property(nonatomic) UITextAutocorrectionType autocorrectionType;
@property(nonatomic) BOOL enablesReturnKeyAutomatically;
@property(nonatomic) UIKeyboardAppearance keyboardAppearance;
@property(nonatomic) UIKeyboardType keyboardType;
@property(nonatomic) UIReturnKeyType returnKeyType;
@property(nonatomic, getter=isSecureTextEntry) BOOL secureTextEntry;
//@property(nonatomic) UITextSpellCheckingType spellCheckingType;


@end