#ifndef __CAR_ELASTOS_CORELIBRARY_H__
#define __CAR_ELASTOS_CORELIBRARY_H__

#ifndef _NO_INCLIST
#include <elastos.h>
using namespace Elastos;
#endif // !_NO_INCLIST


namespace Elastos {
namespace Core {
interface ICharSequence;
EXTERN const _ELASTOS InterfaceID EIID_ICharSequence;
interface IAppendable;
EXTERN const _ELASTOS InterfaceID EIID_IAppendable;
interface ICloneable;
EXTERN const _ELASTOS InterfaceID EIID_ICloneable;
interface IComparable;
EXTERN const _ELASTOS InterfaceID EIID_IComparable;
interface IComparator;
EXTERN const _ELASTOS InterfaceID EIID_IComparator;
interface IStringBuilder;
EXTERN const _ELASTOS InterfaceID EIID_IStringBuilder;
interface IStringBuffer;
EXTERN const _ELASTOS InterfaceID EIID_IStringBuffer;
interface IArrayOf;
EXTERN const _ELASTOS InterfaceID EIID_IArrayOf;
interface INumber;
EXTERN const _ELASTOS InterfaceID EIID_INumber;
interface IBoolean;
EXTERN const _ELASTOS InterfaceID EIID_IBoolean;
interface IByte;
EXTERN const _ELASTOS InterfaceID EIID_IByte;
interface IChar32;
EXTERN const _ELASTOS InterfaceID EIID_IChar32;
interface IInteger16;
EXTERN const _ELASTOS InterfaceID EIID_IInteger16;
interface IInteger32;
EXTERN const _ELASTOS InterfaceID EIID_IInteger32;
interface IInteger64;
EXTERN const _ELASTOS InterfaceID EIID_IInteger64;
interface IFloat;
EXTERN const _ELASTOS InterfaceID EIID_IFloat;
interface IDouble;
EXTERN const _ELASTOS InterfaceID EIID_IDouble;
interface IString;
EXTERN const _ELASTOS InterfaceID EIID_IString;
interface IRunnable;
EXTERN const _ELASTOS InterfaceID EIID_IRunnable;
interface ISynchronize;
EXTERN const _ELASTOS InterfaceID EIID_ISynchronize;
interface IThreadUncaughtExceptionHandler;
EXTERN const _ELASTOS InterfaceID EIID_IThreadUncaughtExceptionHandler;
interface IThread;
EXTERN const _ELASTOS InterfaceID EIID_IThread;
interface IThreadGroup;
EXTERN const _ELASTOS InterfaceID EIID_IThreadGroup;
interface IClassLoader;
EXTERN const _ELASTOS InterfaceID EIID_IClassLoader;
interface IThrowable;
EXTERN const _ELASTOS InterfaceID EIID_IThrowable;
interface IStackTraceElement;
EXTERN const _ELASTOS InterfaceID EIID_IStackTraceElement;
interface IBlockGuardPolicy;
EXTERN const _ELASTOS InterfaceID EIID_IBlockGuardPolicy;
interface IBlockGuard;
EXTERN const _ELASTOS InterfaceID EIID_IBlockGuard;
interface ICloseGuardReporter;
EXTERN const _ELASTOS InterfaceID EIID_ICloseGuardReporter;
interface ICloseGuard;
EXTERN const _ELASTOS InterfaceID EIID_ICloseGuard;
interface ICloseGuardHelper;
EXTERN const _ELASTOS InterfaceID EIID_ICloseGuardHelper;
interface IEnum;
EXTERN const _ELASTOS InterfaceID EIID_IEnum;
interface IThreadLocal;
EXTERN const _ELASTOS InterfaceID EIID_IThreadLocal;
interface ICObjectClassObject;
EXTERN const _ELASTOS InterfaceID EIID_ICObjectClassObject;
interface ICThreadClassObject;
EXTERN const _ELASTOS InterfaceID EIID_ICThreadClassObject;
interface ICThreadGroupClassObject;
EXTERN const _ELASTOS InterfaceID EIID_ICThreadGroupClassObject;
interface ICPathClassLoaderClassObject;
EXTERN const _ELASTOS InterfaceID EIID_ICPathClassLoaderClassObject;
interface ICStringClassObject;
EXTERN const _ELASTOS InterfaceID EIID_ICStringClassObject;
interface ICBooleanClassObject;
EXTERN const _ELASTOS InterfaceID EIID_ICBooleanClassObject;
interface ICByteClassObject;
EXTERN const _ELASTOS InterfaceID EIID_ICByteClassObject;
interface ICChar32ClassObject;
EXTERN const _ELASTOS InterfaceID EIID_ICChar32ClassObject;
interface ICInteger16ClassObject;
EXTERN const _ELASTOS InterfaceID EIID_ICInteger16ClassObject;
interface ICInteger32ClassObject;
EXTERN const _ELASTOS InterfaceID EIID_ICInteger32ClassObject;
interface ICInteger64ClassObject;
EXTERN const _ELASTOS InterfaceID EIID_ICInteger64ClassObject;
interface ICFloatClassObject;
EXTERN const _ELASTOS InterfaceID EIID_ICFloatClassObject;
interface ICDoubleClassObject;
EXTERN const _ELASTOS InterfaceID EIID_ICDoubleClassObject;
interface ICArrayOfClassObject;
EXTERN const _ELASTOS InterfaceID EIID_ICArrayOfClassObject;
EXTERN const _ELASTOS ClassID ECLSID_CObject;
EXTERN const _ELASTOS ClassID ECLSID_CObjectClassObject;
EXTERN const _ELASTOS ClassID ECLSID_CThread;
EXTERN const _ELASTOS ClassID ECLSID_CThreadClassObject;
EXTERN const _ELASTOS ClassID ECLSID_CThreadGroup;
EXTERN const _ELASTOS ClassID ECLSID_CThreadGroupClassObject;
EXTERN const _ELASTOS ClassID ECLSID_CPathClassLoader;
EXTERN const _ELASTOS ClassID ECLSID_CPathClassLoaderClassObject;
EXTERN const _ELASTOS ClassID ECLSID_CString;
EXTERN const _ELASTOS ClassID ECLSID_CStringClassObject;
EXTERN const _ELASTOS ClassID ECLSID_CBoolean;
EXTERN const _ELASTOS ClassID ECLSID_CBooleanClassObject;
EXTERN const _ELASTOS ClassID ECLSID_CByte;
EXTERN const _ELASTOS ClassID ECLSID_CByteClassObject;
EXTERN const _ELASTOS ClassID ECLSID_CChar32;
EXTERN const _ELASTOS ClassID ECLSID_CChar32ClassObject;
EXTERN const _ELASTOS ClassID ECLSID_CInteger16;
EXTERN const _ELASTOS ClassID ECLSID_CInteger16ClassObject;
EXTERN const _ELASTOS ClassID ECLSID_CInteger32;
EXTERN const _ELASTOS ClassID ECLSID_CInteger32ClassObject;
EXTERN const _ELASTOS ClassID ECLSID_CInteger64;
EXTERN const _ELASTOS ClassID ECLSID_CInteger64ClassObject;
EXTERN const _ELASTOS ClassID ECLSID_CFloat;
EXTERN const _ELASTOS ClassID ECLSID_CFloatClassObject;
EXTERN const _ELASTOS ClassID ECLSID_CDouble;
EXTERN const _ELASTOS ClassID ECLSID_CDoubleClassObject;
EXTERN const _ELASTOS ClassID ECLSID_CArrayOf;
EXTERN const _ELASTOS ClassID ECLSID_CArrayOfClassObject;
}
}

namespace Elastos {
namespace IO {
interface ISerializable;
EXTERN const _ELASTOS InterfaceID EIID_ISerializable;
}
}

namespace Elastos {
namespace Math {
interface IMathContext;
EXTERN const _ELASTOS InterfaceID EIID_IMathContext;
interface IMathContextHelper;
EXTERN const _ELASTOS InterfaceID EIID_IMathContextHelper;
interface IBigDecimal;
EXTERN const _ELASTOS InterfaceID EIID_IBigDecimal;
interface IBigDecimalHelper;
EXTERN const _ELASTOS InterfaceID EIID_IBigDecimalHelper;
interface IBigInteger;
EXTERN const _ELASTOS InterfaceID EIID_IBigInteger;
interface IBigIntegerHelper;
EXTERN const _ELASTOS InterfaceID EIID_IBigIntegerHelper;
interface ICBigDecimalClassObject;
EXTERN const _ELASTOS InterfaceID EIID_ICBigDecimalClassObject;
interface ICBigDecimalHelperClassObject;
EXTERN const _ELASTOS InterfaceID EIID_ICBigDecimalHelperClassObject;
interface ICBigIntegerClassObject;
EXTERN const _ELASTOS InterfaceID EIID_ICBigIntegerClassObject;
interface ICBigIntegerHelperClassObject;
EXTERN const _ELASTOS InterfaceID EIID_ICBigIntegerHelperClassObject;
interface ICMathContextClassObject;
EXTERN const _ELASTOS InterfaceID EIID_ICMathContextClassObject;
interface ICMathContextHelperClassObject;
EXTERN const _ELASTOS InterfaceID EIID_ICMathContextHelperClassObject;
EXTERN const _ELASTOS ClassID ECLSID_CBigDecimal;
EXTERN const _ELASTOS ClassID ECLSID_CBigDecimalClassObject;
EXTERN const _ELASTOS ClassID ECLSID_CBigDecimalHelper;
EXTERN const _ELASTOS ClassID ECLSID_CBigDecimalHelperClassObject;
EXTERN const _ELASTOS ClassID ECLSID_CBigInteger;
EXTERN const _ELASTOS ClassID ECLSID_CBigIntegerClassObject;
EXTERN const _ELASTOS ClassID ECLSID_CBigIntegerHelper;
EXTERN const _ELASTOS ClassID ECLSID_CBigIntegerHelperClassObject;
EXTERN const _ELASTOS ClassID ECLSID_CMathContext;
EXTERN const _ELASTOS ClassID ECLSID_CMathContextClassObject;
EXTERN const _ELASTOS ClassID ECLSID_CMathContextHelper;
EXTERN const _ELASTOS ClassID ECLSID_CMathContextHelperClassObject;
}
}

namespace Elastos {
namespace Utility {
interface IBitSet;
EXTERN const _ELASTOS InterfaceID EIID_IBitSet;
interface IBitSetHelper;
EXTERN const _ELASTOS InterfaceID EIID_IBitSetHelper;
interface IDate;
EXTERN const _ELASTOS InterfaceID EIID_IDate;
interface IDateHelper;
EXTERN const _ELASTOS InterfaceID EIID_IDateHelper;
interface IIterable;
EXTERN const _ELASTOS InterfaceID EIID_IIterable;
interface ICollection;
EXTERN const _ELASTOS InterfaceID EIID_ICollection;
interface IList;
EXTERN const _ELASTOS InterfaceID EIID_IList;
interface ILocale;
EXTERN const _ELASTOS InterfaceID EIID_ILocale;
interface IBuilder;
EXTERN const _ELASTOS InterfaceID EIID_IBuilder;
interface ILocaleHelper;
EXTERN const _ELASTOS InterfaceID EIID_ILocaleHelper;
interface ILocaleBuilder;
EXTERN const _ELASTOS InterfaceID EIID_ILocaleBuilder;
interface IMapEntry;
EXTERN const _ELASTOS InterfaceID EIID_IMapEntry;
interface IMap;
EXTERN const _ELASTOS InterfaceID EIID_IMap;
interface IHashMap;
EXTERN const _ELASTOS InterfaceID EIID_IHashMap;
interface IHashSet;
EXTERN const _ELASTOS InterfaceID EIID_IHashSet;
interface IEnumeration;
EXTERN const _ELASTOS InterfaceID EIID_IEnumeration;
interface IHashTable;
EXTERN const _ELASTOS InterfaceID EIID_IHashTable;
interface IIdentityHashMap;
EXTERN const _ELASTOS InterfaceID EIID_IIdentityHashMap;
interface ILinkedHashMap;
EXTERN const _ELASTOS InterfaceID EIID_ILinkedHashMap;
interface ILinkedHashSet;
EXTERN const _ELASTOS InterfaceID EIID_ILinkedHashSet;
interface ILinkedList;
EXTERN const _ELASTOS InterfaceID EIID_ILinkedList;
interface IDictionary;
EXTERN const _ELASTOS InterfaceID EIID_IDictionary;
interface IGregorianCalendar;
EXTERN const _ELASTOS InterfaceID EIID_IGregorianCalendar;
interface IIterator;
EXTERN const _ELASTOS InterfaceID EIID_IIterator;
interface IListIterator;
EXTERN const _ELASTOS InterfaceID EIID_IListIterator;
interface IQueue;
EXTERN const _ELASTOS InterfaceID EIID_IQueue;
interface IDeque;
EXTERN const _ELASTOS InterfaceID EIID_IDeque;
interface IWeakHashMap;
EXTERN const _ELASTOS InterfaceID EIID_IWeakHashMap;
interface ITreeMap;
EXTERN const _ELASTOS InterfaceID EIID_ITreeMap;
interface ITreeSet;
EXTERN const _ELASTOS InterfaceID EIID_ITreeSet;
interface IRandomAccess;
EXTERN const _ELASTOS InterfaceID EIID_IRandomAccess;
interface ICurrency;
EXTERN const _ELASTOS InterfaceID EIID_ICurrency;
interface ICurrencyHelper;
EXTERN const _ELASTOS InterfaceID EIID_ICurrencyHelper;
interface IUUID;
EXTERN const _ELASTOS InterfaceID EIID_IUUID;
interface IUUIDHelper;
EXTERN const _ELASTOS InterfaceID EIID_IUUIDHelper;
interface IArrayList;
EXTERN const _ELASTOS InterfaceID EIID_IArrayList;
interface IFormattableFlags;
EXTERN const _ELASTOS InterfaceID EIID_IFormattableFlags;
interface IFormatter;
EXTERN const _ELASTOS InterfaceID EIID_IFormatter;
interface IFormattable;
EXTERN const _ELASTOS InterfaceID EIID_IFormattable;
interface IArrayDeque;
EXTERN const _ELASTOS InterfaceID EIID_IArrayDeque;
interface IEventListener;
EXTERN const _ELASTOS InterfaceID EIID_IEventListener;
interface IEventListenerProxy;
EXTERN const _ELASTOS InterfaceID EIID_IEventListenerProxy;
interface IEventObject;
EXTERN const _ELASTOS InterfaceID EIID_IEventObject;
interface ISortedMap;
EXTERN const _ELASTOS InterfaceID EIID_ISortedMap;
interface INavigableMap;
EXTERN const _ELASTOS InterfaceID EIID_INavigableMap;
interface ISet;
EXTERN const _ELASTOS InterfaceID EIID_ISet;
interface ISortedSet;
EXTERN const _ELASTOS InterfaceID EIID_ISortedSet;
interface INavigableSet;
EXTERN const _ELASTOS InterfaceID EIID_INavigableSet;
interface IObserver;
EXTERN const _ELASTOS InterfaceID EIID_IObserver;
interface IObservable;
EXTERN const _ELASTOS InterfaceID EIID_IObservable;
interface IPriorityQueue;
EXTERN const _ELASTOS InterfaceID EIID_IPriorityQueue;
interface IEnumSet;
EXTERN const _ELASTOS InterfaceID EIID_IEnumSet;
interface IEnumSetHelper;
EXTERN const _ELASTOS InterfaceID EIID_IEnumSetHelper;
interface IHugeEnumSet;
EXTERN const _ELASTOS InterfaceID EIID_IHugeEnumSet;
interface IMiniEnumSet;
EXTERN const _ELASTOS InterfaceID EIID_IMiniEnumSet;
interface IServiceLoader;
EXTERN const _ELASTOS InterfaceID EIID_IServiceLoader;
interface IServiceLoaderHelper;
EXTERN const _ELASTOS InterfaceID EIID_IServiceLoaderHelper;
interface IVector;
EXTERN const _ELASTOS InterfaceID EIID_IVector;
interface IStack;
EXTERN const _ELASTOS InterfaceID EIID_IStack;
interface IStringTokenizer;
EXTERN const _ELASTOS InterfaceID EIID_IStringTokenizer;
interface IUnsafeArrayList;
EXTERN const _ELASTOS InterfaceID EIID_IUnsafeArrayList;
interface IPropertyPermission;
EXTERN const _ELASTOS InterfaceID EIID_IPropertyPermission;
interface IReverseComparator;
EXTERN const _ELASTOS InterfaceID EIID_IReverseComparator;
interface IReverseComparator2;
EXTERN const _ELASTOS InterfaceID EIID_IReverseComparator2;
interface ICollections;
EXTERN const _ELASTOS InterfaceID EIID_ICollections;
interface IEnumMap;
EXTERN const _ELASTOS InterfaceID EIID_IEnumMap;
interface ICStringTokenizerClassObject;
EXTERN const _ELASTOS InterfaceID EIID_ICStringTokenizerClassObject;
interface ICArrayDequeClassObject;
EXTERN const _ELASTOS InterfaceID EIID_ICArrayDequeClassObject;
interface ICArrayListClassObject;
EXTERN const _ELASTOS InterfaceID EIID_ICArrayListClassObject;
interface ICArrayListIteratorClassObject;
EXTERN const _ELASTOS InterfaceID EIID_ICArrayListIteratorClassObject;
interface ICSimpleListIteratorClassObject;
EXTERN const _ELASTOS InterfaceID EIID_ICSimpleListIteratorClassObject;
interface ICFullListIteratorClassObject;
EXTERN const _ELASTOS InterfaceID EIID_ICFullListIteratorClassObject;
interface ICSubAbstractListIteratorClassObject;
EXTERN const _ELASTOS InterfaceID EIID_ICSubAbstractListIteratorClassObject;
interface ICSubAbstractListClassObject;
EXTERN const _ELASTOS InterfaceID EIID_ICSubAbstractListClassObject;
interface ICRandomAccessSubListClassObject;
EXTERN const _ELASTOS InterfaceID EIID_ICRandomAccessSubListClassObject;
interface ICBitSetClassObject;
EXTERN const _ELASTOS InterfaceID EIID_ICBitSetClassObject;
interface ICBitSetHelperClassObject;
EXTERN const _ELASTOS InterfaceID EIID_ICBitSetHelperClassObject;
interface ICEnumMapClassObject;
EXTERN const _ELASTOS InterfaceID EIID_ICEnumMapClassObject;
interface ICHashMapClassObject;
EXTERN const _ELASTOS InterfaceID EIID_ICHashMapClassObject;
interface ICHashSetClassObject;
EXTERN const _ELASTOS InterfaceID EIID_ICHashSetClassObject;
interface ICHashTableClassObject;
EXTERN const _ELASTOS InterfaceID EIID_ICHashTableClassObject;
interface ICLinkedHashMapClassObject;
EXTERN const _ELASTOS InterfaceID EIID_ICLinkedHashMapClassObject;
interface ICLinkedHashSetClassObject;
EXTERN const _ELASTOS InterfaceID EIID_ICLinkedHashSetClassObject;
interface ICLinkedListClassObject;
EXTERN const _ELASTOS InterfaceID EIID_ICLinkedListClassObject;
interface ICVectorClassObject;
EXTERN const _ELASTOS InterfaceID EIID_ICVectorClassObject;
interface ICStackClassObject;
EXTERN const _ELASTOS InterfaceID EIID_ICStackClassObject;
interface ICWeakHashMapClassObject;
EXTERN const _ELASTOS InterfaceID EIID_ICWeakHashMapClassObject;
interface ICTreeMapClassObject;
EXTERN const _ELASTOS InterfaceID EIID_ICTreeMapClassObject;
interface ICTreeSetClassObject;
EXTERN const _ELASTOS InterfaceID EIID_ICTreeSetClassObject;
interface ICPriorityQueueClassObject;
EXTERN const _ELASTOS InterfaceID EIID_ICPriorityQueueClassObject;
interface ICHugeEnumSetClassObject;
EXTERN const _ELASTOS InterfaceID EIID_ICHugeEnumSetClassObject;
interface ICMiniEnumSetClassObject;
EXTERN const _ELASTOS InterfaceID EIID_ICMiniEnumSetClassObject;
interface ICUnsafeArrayListClassObject;
EXTERN const _ELASTOS InterfaceID EIID_ICUnsafeArrayListClassObject;
interface ICCollectionsClassObject;
EXTERN const _ELASTOS InterfaceID EIID_ICCollectionsClassObject;
interface ICEnumSetHelperClassObject;
EXTERN const _ELASTOS InterfaceID EIID_ICEnumSetHelperClassObject;
EXTERN const _ELASTOS ClassID ECLSID_CStringTokenizer;
EXTERN const _ELASTOS ClassID ECLSID_CStringTokenizerClassObject;
EXTERN const _ELASTOS ClassID ECLSID_CArrayDeque;
EXTERN const _ELASTOS ClassID ECLSID_CArrayDequeClassObject;
EXTERN const _ELASTOS ClassID ECLSID_CArrayList;
EXTERN const _ELASTOS ClassID ECLSID_CArrayListClassObject;
EXTERN const _ELASTOS ClassID ECLSID_CArrayListIterator;
EXTERN const _ELASTOS ClassID ECLSID_CArrayListIteratorClassObject;
EXTERN const _ELASTOS ClassID ECLSID_CSimpleListIterator;
EXTERN const _ELASTOS ClassID ECLSID_CSimpleListIteratorClassObject;
EXTERN const _ELASTOS ClassID ECLSID_CFullListIterator;
EXTERN const _ELASTOS ClassID ECLSID_CFullListIteratorClassObject;
EXTERN const _ELASTOS ClassID ECLSID_CSubAbstractListIterator;
EXTERN const _ELASTOS ClassID ECLSID_CSubAbstractListIteratorClassObject;
EXTERN const _ELASTOS ClassID ECLSID_CSubAbstractList;
EXTERN const _ELASTOS ClassID ECLSID_CSubAbstractListClassObject;
EXTERN const _ELASTOS ClassID ECLSID_CRandomAccessSubList;
EXTERN const _ELASTOS ClassID ECLSID_CRandomAccessSubListClassObject;
EXTERN const _ELASTOS ClassID ECLSID_CBitSet;
EXTERN const _ELASTOS ClassID ECLSID_CBitSetClassObject;
EXTERN const _ELASTOS ClassID ECLSID_CBitSetHelper;
EXTERN const _ELASTOS ClassID ECLSID_CBitSetHelperClassObject;
EXTERN const _ELASTOS ClassID ECLSID_CEnumMap;
EXTERN const _ELASTOS ClassID ECLSID_CEnumMapClassObject;
EXTERN const _ELASTOS ClassID ECLSID_CHashMap;
EXTERN const _ELASTOS ClassID ECLSID_CHashMapClassObject;
EXTERN const _ELASTOS ClassID ECLSID_CHashSet;
EXTERN const _ELASTOS ClassID ECLSID_CHashSetClassObject;
EXTERN const _ELASTOS ClassID ECLSID_CHashTable;
EXTERN const _ELASTOS ClassID ECLSID_CHashTableClassObject;
EXTERN const _ELASTOS ClassID ECLSID_CLinkedHashMap;
EXTERN const _ELASTOS ClassID ECLSID_CLinkedHashMapClassObject;
EXTERN const _ELASTOS ClassID ECLSID_CLinkedHashSet;
EXTERN const _ELASTOS ClassID ECLSID_CLinkedHashSetClassObject;
EXTERN const _ELASTOS ClassID ECLSID_CLinkedList;
EXTERN const _ELASTOS ClassID ECLSID_CLinkedListClassObject;
EXTERN const _ELASTOS ClassID ECLSID_CVector;
EXTERN const _ELASTOS ClassID ECLSID_CVectorClassObject;
EXTERN const _ELASTOS ClassID ECLSID_CStack;
EXTERN const _ELASTOS ClassID ECLSID_CStackClassObject;
EXTERN const _ELASTOS ClassID ECLSID_CWeakHashMap;
EXTERN const _ELASTOS ClassID ECLSID_CWeakHashMapClassObject;
EXTERN const _ELASTOS ClassID ECLSID_CTreeMap;
EXTERN const _ELASTOS ClassID ECLSID_CTreeMapClassObject;
EXTERN const _ELASTOS ClassID ECLSID_CTreeSet;
EXTERN const _ELASTOS ClassID ECLSID_CTreeSetClassObject;
EXTERN const _ELASTOS ClassID ECLSID_CPriorityQueue;
EXTERN const _ELASTOS ClassID ECLSID_CPriorityQueueClassObject;
EXTERN const _ELASTOS ClassID ECLSID_CHugeEnumSet;
EXTERN const _ELASTOS ClassID ECLSID_CHugeEnumSetClassObject;
EXTERN const _ELASTOS ClassID ECLSID_CMiniEnumSet;
EXTERN const _ELASTOS ClassID ECLSID_CMiniEnumSetClassObject;
EXTERN const _ELASTOS ClassID ECLSID_CUnsafeArrayList;
EXTERN const _ELASTOS ClassID ECLSID_CUnsafeArrayListClassObject;
EXTERN const _ELASTOS ClassID ECLSID_CCollections;
EXTERN const _ELASTOS ClassID ECLSID_CCollectionsClassObject;
EXTERN const _ELASTOS ClassID ECLSID_CEnumSetHelper;
EXTERN const _ELASTOS ClassID ECLSID_CEnumSetHelperClassObject;
}
}

namespace Elastos {
namespace Utility {
namespace Regex {
interface IMatchResult;
EXTERN const _ELASTOS InterfaceID EIID_IMatchResult;
interface IMatcher;
EXTERN const _ELASTOS InterfaceID EIID_IMatcher;
interface IMatcherHelper;
EXTERN const _ELASTOS InterfaceID EIID_IMatcherHelper;
interface ISplitter;
EXTERN const _ELASTOS InterfaceID EIID_ISplitter;
interface IPattern;
EXTERN const _ELASTOS InterfaceID EIID_IPattern;
interface IPatternHelper;
EXTERN const _ELASTOS InterfaceID EIID_IPatternHelper;
interface ICMatcherClassObject;
EXTERN const _ELASTOS InterfaceID EIID_ICMatcherClassObject;
interface ICMatcherHelperClassObject;
EXTERN const _ELASTOS InterfaceID EIID_ICMatcherHelperClassObject;
interface ICSplitterClassObject;
EXTERN const _ELASTOS InterfaceID EIID_ICSplitterClassObject;
interface ICPatternHelperClassObject;
EXTERN const _ELASTOS InterfaceID EIID_ICPatternHelperClassObject;
EXTERN const _ELASTOS ClassID ECLSID_CMatcher;
EXTERN const _ELASTOS ClassID ECLSID_CMatcherClassObject;
EXTERN const _ELASTOS ClassID ECLSID_CMatcherHelper;
EXTERN const _ELASTOS ClassID ECLSID_CMatcherHelperClassObject;
EXTERN const _ELASTOS ClassID ECLSID_CSplitter;
EXTERN const _ELASTOS ClassID ECLSID_CSplitterClassObject;
EXTERN const _ELASTOS ClassID ECLSID_CPatternHelper;
EXTERN const _ELASTOS ClassID ECLSID_CPatternHelperClassObject;
}
}
}




#ifndef E_OUT_OF_MEMORY_ERROR
#define E_OUT_OF_MEMORY_ERROR 0xa1010000
#endif

#ifndef E_ASSERTION_ERROR
#define E_ASSERTION_ERROR 0xa1020000
#endif

#ifndef E_INTERNAL_ERROR
#define E_INTERNAL_ERROR 0xa1030000
#endif

#ifndef E_ILLEGAL_ACCESS_ERROR
#define E_ILLEGAL_ACCESS_ERROR 0xa1040000
#endif

#ifndef E_VERIFY_ERROR
#define E_VERIFY_ERROR 0xa1050000
#endif

#ifndef E_UNKNOWN_ERROR
#define E_UNKNOWN_ERROR 0xa1060000
#endif

#ifndef E_ABSTRACET_METHOD_ERROR
#define E_ABSTRACET_METHOD_ERROR 0xa1070000
#endif

#ifndef E_ARRAY_INDEX_OUT_OF_BOUNDS_EXCEPTION
#define E_ARRAY_INDEX_OUT_OF_BOUNDS_EXCEPTION 0xa0010000
#endif

#ifndef E_ILLEGAL_ARGUMENT_EXCEPTION
#define E_ILLEGAL_ARGUMENT_EXCEPTION 0xa0020000
#endif

#ifndef E_INDEX_OUT_OF_BOUNDS_EXCEPTION
#define E_INDEX_OUT_OF_BOUNDS_EXCEPTION 0xa0030000
#endif

#ifndef E_NULL_POINTER_EXCEPTION
#define E_NULL_POINTER_EXCEPTION 0xa0040000
#endif

#ifndef E_RUNTIME_EXCEPTION
#define E_RUNTIME_EXCEPTION 0xa0050000
#endif

#ifndef E_ILLEGAL_STATE_EXCEPTION
#define E_ILLEGAL_STATE_EXCEPTION 0xa0060000
#endif

#ifndef E_ILLEGAL_THREAD_STATE_EXCEPTION
#define E_ILLEGAL_THREAD_STATE_EXCEPTION 0xa0070000
#endif

#ifndef E_UNSUPPORTED_OPERATION_EXCEPTION
#define E_UNSUPPORTED_OPERATION_EXCEPTION 0xa0080000
#endif

#ifndef E_SECURITY_EXCEPTION
#define E_SECURITY_EXCEPTION 0xa0090000
#endif

#ifndef E_STRING_INDEX_OUT_OF_BOUNDS_EXCEPTION
#define E_STRING_INDEX_OUT_OF_BOUNDS_EXCEPTION 0xa00a0000
#endif

#ifndef E_NO_SUCH_METHOD_EXCEPTION
#define E_NO_SUCH_METHOD_EXCEPTION 0xa00b0000
#endif

#ifndef E_ILLEGAL_MONITOR_STATE_EXCEPTION
#define E_ILLEGAL_MONITOR_STATE_EXCEPTION 0xa00c0000
#endif

#ifndef E_INTERRUPTED_EXCEPTION
#define E_INTERRUPTED_EXCEPTION 0xa00d0000
#endif

#ifndef E_ARITHMETIC_EXCEPTION
#define E_ARITHMETIC_EXCEPTION 0xa00e0000
#endif

#ifndef E_REMOTE_EXCEPTION
#define E_REMOTE_EXCEPTION 0x801c0000
#endif

#ifndef E_NOT_FOUND_EXCEPTION
#define E_NOT_FOUND_EXCEPTION 0xa0100000
#endif

#ifndef E_SUPER_NOT_CALLED_EXCEPTION
#define E_SUPER_NOT_CALLED_EXCEPTION 0xa0110000
#endif

#ifndef E_CLASS_NOT_FOUND_EXCEPTION
#define E_CLASS_NOT_FOUND_EXCEPTION 0xa0120000
#endif

#ifndef E_NEGATIVE_ARRAY_SIZE_EXCEPTION
#define E_NEGATIVE_ARRAY_SIZE_EXCEPTION 0xa0130000
#endif

#ifndef E_NUMBER_FORMAT_EXCEPTION
#define E_NUMBER_FORMAT_EXCEPTION 0xa0140000
#endif

#ifndef E_PATTERN_SYNTAX_EXCEPTION
#define E_PATTERN_SYNTAX_EXCEPTION 0xa0150000
#endif

#ifndef E_CLONE_NOT_SUPPORTED_EXCEPTION
#define E_CLONE_NOT_SUPPORTED_EXCEPTION 0xa0160000
#endif

#ifndef E_NAGATIVE_ARRAY_SIZE_EXCEPTION
#define E_NAGATIVE_ARRAY_SIZE_EXCEPTION 0xa0170000
#endif

#ifndef E_ILLEGAL_ACCESS_EXCEPTION
#define E_ILLEGAL_ACCESS_EXCEPTION 0xa0180000
#endif

#ifndef E_NO_SUCH_FIELD_EXCEPTION
#define E_NO_SUCH_FIELD_EXCEPTION 0xa0190000
#endif

#ifndef E_CLASS_CAST_EXCEPTION
#define E_CLASS_CAST_EXCEPTION 0xa0200000
#endif

#ifndef E_ARRAY_STORE_EXCEPTION
#define E_ARRAY_STORE_EXCEPTION 0xa0210000
#endif

#ifndef E_NO_SUCH_ELEMENT_EXCEPTION
#define E_NO_SUCH_ELEMENT_EXCEPTION 0xab000000
#endif

#ifndef E_CONCURRENT_MODIFICATION_EXCEPTION
#define E_CONCURRENT_MODIFICATION_EXCEPTION 0xa7000000
#endif

#ifndef E_FORMATTER_CLOSED_EXCEPTION
#define E_FORMATTER_CLOSED_EXCEPTION 0xa7000001
#endif

#ifndef E_MISSING_FORMAT_ARGUMENT_EXCEPTION
#define E_MISSING_FORMAT_ARGUMENT_EXCEPTION 0xa7000002
#endif

#ifndef E_ILLEGAL_FORMAT_CONVERSION_EXCEPTION
#define E_ILLEGAL_FORMAT_CONVERSION_EXCEPTION 0xa7000003
#endif

#ifndef E_ILLEGAL_FORMAT_FLAGS_EXCEPTION
#define E_ILLEGAL_FORMAT_FLAGS_EXCEPTION 0xa7000004
#endif

#ifndef E_UNKNOWN_FORMAT_CONVERSION_EXCEPTION
#define E_UNKNOWN_FORMAT_CONVERSION_EXCEPTION 0xa7000005
#endif

#ifndef E_FORMAT_FLAGS_CONVERSION_MISMATCH_EXCEPTION
#define E_FORMAT_FLAGS_CONVERSION_MISMATCH_EXCEPTION 0xa7000006
#endif

#ifndef E_MISSING_FORMAT_WIDTH_EXCEPTION
#define E_MISSING_FORMAT_WIDTH_EXCEPTION 0xa7000007
#endif

#ifndef E_ILLEGAL_FORMAT_PRECISION_EXCEPTION
#define E_ILLEGAL_FORMAT_PRECISION_EXCEPTION 0xa7000008
#endif

#ifndef E_ILLEGAL_FORMAT_WIDTH_EXCEPTION
#define E_ILLEGAL_FORMAT_WIDTH_EXCEPTION 0xa7000009
#endif

#ifndef E_EMPTY_STACK_EXCEPTION
#define E_EMPTY_STACK_EXCEPTION 0xa700000a
#endif

#ifndef E_INPUT_MISMATCH_EXCEPTION
#define E_INPUT_MISMATCH_EXCEPTION 0xa700000b
#endif

#ifndef E_MISSING_RESOURCE_EXCEPTION
#define E_MISSING_RESOURCE_EXCEPTION 0xa700000c
#endif

#ifndef E_BROKEN_BARRIER_EXCEPTION
#define E_BROKEN_BARRIER_EXCEPTION 0xa700000d
#endif

#ifndef E_ILLFORMED_LOCALE_EXCEPTION
#define E_ILLFORMED_LOCALE_EXCEPTION 0xa700000e
#endif

#ifndef E_BACKING_STORE_EXCEPTION
#define E_BACKING_STORE_EXCEPTION 0xa700000f
#endif

#ifndef E_CHECKED_ARITHMETIC_EXCEPTION
#define E_CHECKED_ARITHMETIC_EXCEPTION 0xa7000010
#endif

#ifndef E_INVALID_PREFERENCES_FORMAT_EXCEPTION
#define E_INVALID_PREFERENCES_FORMAT_EXCEPTION 0xa7000011
#endif

#ifndef E_JAR_EXCEPTION
#define E_JAR_EXCEPTION 0xa7000012
#endif


#ifndef __ENUM_Elastos_Core_ThreadState__
#define __ENUM_Elastos_Core_ThreadState__
namespace Elastos {
namespace Core {
enum {
    ThreadState_NEW = 0,
    ThreadState_RUNNABLE = 1,
    ThreadState_BLOCKED = 2,
    ThreadState_WAITING = 3,
    ThreadState_TIMED_WAITING = 4,
    ThreadState_TERMINATED = 5,
};
typedef _ELASTOS Int32 ThreadState;
}
}

#endif //__ENUM_Elastos_Core_ThreadState__


#ifndef __ENUM_Elastos_Math_RoundingMode__
#define __ENUM_Elastos_Math_RoundingMode__
namespace Elastos {
namespace Math {
enum {
    RoundingMode_UP = 0,
    RoundingMode_DOWN = 1,
    RoundingMode_CEILING = 2,
    RoundingMode_FLOOR = 3,
    RoundingMode_HALF_UP = 4,
    RoundingMode_HALF_DOWN = 5,
    RoundingMode_HALF_EVEN = 6,
    RoundingMode_UNNECESSARY = 7,
};
typedef _ELASTOS Int32 RoundingMode;
}
}

#endif //__ENUM_Elastos_Math_RoundingMode__

typedef _ELASTOS PVoid LocalPtr;

#ifdef __ELASTOS_CORELIBRARY_USER_TYPE_H__
#include "Elastos.CoreLibrary_user_type.h"
#endif

#endif // __CAR_ELASTOS_CORELIBRARY_H__
